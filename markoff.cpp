#include "markoff.h"
#include "cstdio"
#include "iostream"
#include "map"
#include "vector"
#include "string"
#include <fstream>
#include <cstring>
#include "sstream"
#include <time.h>
#include <conio.h>
#include "chrono"
#include "thread"
#include "set"
#include "vector"
#include "list"

using namespace std;

const int delimeter = -127;

string mx(map_it begin, map_it end) {

	map_it mxt;
	int xx = INT_MIN;
	for (map_it it = begin; it != end; it++) {
		if (it->second > xx) {
			mxt = it;
			xx = it->second;
		}
	}

	return mxt->first;
}

void teach(dict *words, string s) {
	stringstream ss(s);
	string t, t1;
	ss >> t;
	while ((t1 = t).length() != 0 && (ss >> t)) {
		(*words)[t1][t]++;
	}
}

string get_next(dict* words, string s) {
	map<string, int> g = (*words)[s];
	
	if(g.begin() == g.end())
		return ".";

	return mx(g.begin(), g.end());
}

string generate_sentence(dict* words, int rand_num) {
	string result  = "";
	_it _iterator = (*words).begin();
	
	for (int i = 0; i < rand_num % distance((*words).begin(), (*words).end()); i++)
		_iterator++;

	result += _iterator->first + " ";

	int cycle = 0;

	set<string> wwords;

	while (true) {
		cycle++;
		map<string, int> g = (*words)[_iterator->first];
		list < pair < string, int > > gg;
		for (map_it it__ = g.begin(); it__ != g.end(); it__++)
			gg.push_back(pair<string, int>(it__->first, it__->second));
		gg.sort([](const pair<string, int> &a, const pair<string, int> &b) { return a.second > b.second; });

		list < pair < string, int > >::iterator list_it = gg.begin();
		string _mx = list_it->first;

		while (list_it != gg.end() && wwords.find(_mx) != wwords.end())
			_mx = (++list_it)->first;

		if (list_it == gg.end()) {
			cout << "*ENDS*" << '\n';
			break;
		}

		wwords.insert(_mx);
		cout << _mx << ' ';

		bool found = false;
		for (_it it = (*words).begin(); it != (*words).end(); it++) {
			if (it->first == _mx) {
				_iterator = it;
				found = true;
			}
		}
		if (!found) {
			cout << "*ENDS*" << '\n';
			break;
		}
	}

}

void teach_from_file(dict *words, string file_name) {
	ifstream in(file_name);
	string s;

	while(getline(in, s)) {
		int t = 0;
		while(t < s.length()) {
			if(s[t++] == delimeter) {
				break;
			}
		}

		/*
		for(int i = 0; i < s.length(); i ++) {
			cerr << (int)s[i] << ' ';
		}
		cerr << '\n';
		*/
		if(t == s.length() - 1)
			continue;

		string word = s.substr(0, t);
		s = s.substr(t);
		
		/*
		cerr << "word=" << word << '\n';
		return;
		*/

		while(s.length() != 0) {
			string lword;
			int tword = 0;
			string count;
			int tcount = 0;
			while(tword < s.length()) {
				if(s[tword++] == delimeter) {
					break;
				}
			}
			lword = s.substr(0, tword);
			s = s.substr(tword);
			while(tcount < s.length()) {
				if(s[tcount++] == delimeter) {
					break;
				}
			}

			count = s.substr(0, tcount);
			s = s.substr(tcount);
			cout << "count=" << count << '\n';
			int icount;
			if(count.length() != 0)
				icount = stoi(count);
			else
				continue;
			//for(int i = 0; i < icount; i++)
			(*words)[word][lword] = icount;
			cerr << word << ' ' << lword << ' ' << icount;
		}
	}
}