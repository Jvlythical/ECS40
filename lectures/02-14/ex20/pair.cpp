#include <iostream>
using namespace std;

//Class for a pair of values of type T
template<class T>
class Pair
{
public:
    Pair();
    Pair(T fst, T snd);
    void setFirst(T v);
    void setSecond(T v);
    T getFirst() const;
    T getSecond() const;
private:
    T first;
    T second;
};

template<class T>
Pair<T>::Pair(T fst, T snd) : first(fst), second(snd)
{
  // empty
}

template<class T>
void Pair<T>::setFirst(T v)
{
  first = v;
}

template<class T>
T Pair<T>::getFirst( ) const
{
  return first;
}

int main( )
{
    Pair<char> p('A', 'B');
    cout << "First is " << p.getFirst() << endl;
    p.setFirst('Z');
    cout << "First changed to " << p.getFirst() << endl;
 
    return 0;
}
