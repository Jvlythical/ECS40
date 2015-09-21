#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main () {
	ostream_iterator <int> oi (cout, " ");
	vector <int> v;

	v.push_back (1);
	v.push_back (2);

	//copy (v.begin(), v.end(), oi);

	*oi = 1;

	return 0;
}
