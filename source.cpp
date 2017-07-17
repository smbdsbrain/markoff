#include <cstdio>
#include "markoff.h"
using namespace std;


dict words;

int main() {
	freopen("input.txt", "r", stdin);

	string s;
	while (getline(cin, s)) {
		teach(&words, s);
		//cerr << s << '\n';
	}


	//Пока не работает
	//teach_from_file(&words, "cppto.txt");

	setlocale(LC_ALL, "Russian");
	cout << "calculated \n";
	srand(time(NULL)); 

	while(true) {
		generate_sentence(&words, rand());
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
	}
}