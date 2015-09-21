#include <iostream>
#include <fstream>

using namespace std;

int main () {
	ofstream of ("test2.cc", ios::app);
	fstream is ("test.cc");
	string tok, new_str;
	
	while (is) {
		getline (is, new_str);
		of << new_str;
	}

	cout << new_str.at(100)<< endl;


	return 0;
}
