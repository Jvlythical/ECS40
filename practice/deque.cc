#include <iostream>
#include <deque>
#include <ctime>
#include <algorithm>

using namespace std;

int binarySearch (int key, deque<int>haystack, int low, int high) {
	int middle = (low + high) / 2;

	if (low > high) return -1;

	if (haystack[middle] == key) return middle;
	if (haystack[middle] < key) return binarySearch (key, haystack, low, middle - 1);
	else return binarySearch (key, haystack, middle + 1, high);
}

int main () {
	deque<int> d;
	deque<int>::iterator it = d.begin ();
	int size = 10, loc;
	srand (time (0));

	for (int i = 0; i < size; i++) {
		//d.push_back (10 + rand() % 90);
		d.push_back (i);
	}

	sort (d.begin(), d.end());

	loc = binarySearch (5, d, 0, d.size ());
	cout << "Location: " << loc << endl;

	for (it = d.begin(); it < d.end(); it++) cout << *(it) << endl;
	
	return 0;
}
