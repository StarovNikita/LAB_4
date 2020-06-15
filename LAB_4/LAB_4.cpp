#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyArray
{
    T* arr;
    int _n;
public:
    class Iterator;
    MyArray(int n = 1) : _n(n)
    {
        arr = new T[n];
    }
    T& operator[] (const int& n)
    {
        if (n > 0 && n < _n)
            return arr[n];
        return arr[0];
    }
    Iterator begin()
    {
        return arr;
    }
    Iterator end()
    {
        return arr + _n;
    }
    friend ostream& operator<< (ostream& s, const MyArray<T>& n);
    class Iterator
    {
        T* cur;
    public:
        Iterator(T* first) : cur(first)
        {}

        T& operator+ (int n) { return *(cur + n); }
        T& operator- (int n) { return *(cur - n); }

        T& operator++ (int) { return *cur++; }
        T& operator-- (int) { return *cur--; }
        T& operator++ () { return *++cur; }
        T& operator-- () { return *--cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator == (const Iterator& it) { return cur == it.cur; }
        T& operator* () { return *cur; }
    };
};

template <typename T>
ostream& operator<<(ostream& s, const MyArray<T>& n)
{
    s << MyArray<T>::arr[n];
    return s;
}
int main() {
     
    MyArray<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    auto it = MyArray<int>::Iterator(arr.begin());
    cout << *it << endl;

    vector<int> MyVector = { 1,2,3 };
    vector<int>::iterator It=MyVector.begin();
    cout << *(It);

    return 0;
}