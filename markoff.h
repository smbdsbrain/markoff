#include "cstdio"
#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "sstream"
#include <time.h>
#include <conio.h>
#include "chrono"
#include "thread"
#include "set"
#include "vector"
#include "list"
using namespace std;

typedef map<string, int>::iterator map_it;
typedef map<string, map<string, int>>::iterator _it;
typedef map<string, map<string, int>> dict;


string mx(map_it begin, map_it end);
void teach(dict *words, string s);
void teach_from_file(dict *words, string file_name);
string get_next_word(dict* words, string s);
string generate_sentence(dict* words, int rand_num);