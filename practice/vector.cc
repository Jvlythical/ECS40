#include <iostream>
#include <vector>

using namespace std;

int main () {
	vector<int> v;

	v.push_back (1);
	v.push_back (2);

	cout << *(--v.end()) << endl;

	for (vector<int>::iterator it = v.begin(); it < v.end (); it++) cout << *it << endl;

	return 0;
}
