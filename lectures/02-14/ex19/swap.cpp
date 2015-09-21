#include <iostream>
using namespace std;

template<typename T>
void myswap(T& v1, T& v2)
{
  T t;

  t = v1;
  v1 = v2;
  v2 = t;
}

int main( )
{
    int i = 1, j = 2;
    cout << "Original values: " << i << " " << j << endl;

    myswap(i, j);
    cout << "After swap: "  << i << " " << j << endl;

    char c1 = 'X', c2 = 'Y';
    cout << "Original char: " << c1 << " " << c2 << endl; 

    myswap(c1, c2);
    cout << "After swap: " << c1 << " " << c2 << endl;

    return 0;
}
