#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main () {
	const char  *s = "moop";
	char str[128];
	int d = 3;

	istringstream ss (s);
	//cout << bool (ss >> str) << endl;
	
	//cout << str;

	int a = 99;
	int b = 77;
	int c = 63;

	printf (" %5lu %3d %+1.2f \n", a, b, c / 100.0);
	cout << setw (6) <<  a << setw (4) << b << " ";
	cout << setprecision(2) << "+" << c / 100.0 << " "<< endl;

	return 0;
}
