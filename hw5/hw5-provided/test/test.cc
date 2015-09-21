#include <iostream> 
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main () {
	string s, temp;

	getline (cin, s);
	cout << cin.peek () << endl;
	cout << s << endl;
	getline (cin, s);
	cout << s << endl;

	cout << fixed << endl;
	cout << setprecision (5) << M_PI << endl;

	cout << M_PI << endl;
	return 0;
}
