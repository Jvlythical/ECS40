#include <iostream>
using namespace std;

template<class T>
void myswap(T& v1, T& v2)
{
  T t;

  t = v1;
  v1 = v2;
  v2 = t;
}

template<class T>
int findIdx(const T a[], int start, int used)
{
    T min = a[start];
    int idxMin = start;

    for (int i = start + 1; i < used; i++)
      if (a[i] < min) {
	min = a[i];
	idxMin = i;
	// note: min is the smallest of a[start] through a[i]
      }

    return idxMin;
}

template<class T>
void sort(T a[], int used)
{
  int idx; // index of the next smallest 

  for (int i = 0; i < used - 1; i++) {

    //Place the correct value in a[i]:
    idx = findIdx (a, i, used);

    myswap(a[i], a[idx]);
  }
}

int main( )
{
    int i;
    int a[10] = {9, 8, 7, 6, 5, 1, 2, 3, 0, 4};
    cout << "Unsorted integers:\n";
    for (i = 0; i < 10; i++)
      cout << a[i] << " ";
    cout << endl;

    sort(a, 10);
    cout << "In sorted order the integers are:\n";
    for (i = 0; i < 10; i++)
      cout << a[i] << " ";
    cout << endl;

    double b[5] = {5.5, 4.4, 1.1, 3.3, 2.2};
    cout << "Unsorted doubles:\n";
    for (i = 0; i < 5; i++)
      cout << b[i] << " ";
    cout << endl;

    sort(b, 5);
    cout << "In sorted order the doubles are:\n";
    for (i = 0; i < 5; i++)
      cout << b[i] << " ";
    cout << endl;

    char c[7] = {'G', 'E', 'N', 'E', 'R', 'I', 'C'};
    cout << "Unsorted characters:\n";
    for (i = 0; i < 7; i++)
      cout << c[i] << " ";
    cout << endl;

    sort(c, 7);
    cout << "In sorted order the characters are:\n";
    for (i = 0; i < 7; i++)
      cout << c[i] << " ";
    cout << endl;

    return 0;
}
