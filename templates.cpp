#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Array
{
public:
    T* pData;
    size_t length;
    
    T& operator[](size_t i);
    
    
    Array(size_t size);
    
    
    ~Array()
    {
        cout << "deleting" << endl;
        delete[] pData;
    }
};

template <class T>
Array<T>::Array(size_t size)
{
    this->length = size;
    pData = new T[size];
}

template <class T>
T& Array<T>::operator[](size_t i)
{
    return *(pData + (i % length));
}

int main()
{
    size_t k = 20;
    Array<int> ia(k);
    Array<double> da(k);
    
    ia[0] = 5;
    
    cout << ia[0] << endl;
    
    for (int i = 0; i < k; i++) {
        ia[i] = i;
        da[i] = i + 0.05;
    }
    
    for (int i = 0; i < 30; i++) {
        cout << ia[i] << ' ';
    }
    
    cout << endl;
    
    for (int i = 0; i < k; i++) {
        cout << da[i] << ' ';
    }
    cout << endl;
}