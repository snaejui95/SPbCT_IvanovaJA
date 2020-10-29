#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

template<class T>
class Array {
public:
    Array();
    Array(const initializer_list<T>&);
    Array(const size_t size);
    Array(const Array&);
    Array& operator = (const Array&);
    ~Array();
    T* begin() const;
    T* end() const;
    T& operator [](const size_t);
    const T& operator [](const size_t) const;
    size_t size() const;
    Array& operator +(const Array&);
    void operator +(T);
private:
    void swap(Array&, Array&);
    T* m_data;
    size_t m_size;
};

template <typename T>
Array<T>::Array() : m_data(nullptr), m_size(0) {}

template<class T>
Array<T>::Array(const size_t size) : m_data(new T[size]), m_size(size) {
    fill(m_data, m_data + m_size, T());
}

template<class T>
Array<T>::Array(const initializer_list<T>& il) : m_data(new T[il.size()]), m_size(il.size()) {
    copy(il.begin(), il.end(), m_data);
}

template <class T>
Array<T>::Array(const Array& arr) {
    m_size = arr.m_size;
    if (arr.m_data) {
        m_data = new T[m_size];
        copy(arr.m_data, arr.m_data + m_size, m_data);
    }
    else m_data = nullptr;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& arr) {
    if (this != &arr)
        Array(arr).swap(*this);
    return *this;
}

template <class T>
Array<T>::~Array() {
    delete[] m_data;
}

template <class T>
T* Array<T>::begin() const {
    return m_data;
}

template <class T>
T* Array<T>::end() const {
    return m_data + m_size;
}

template <class T>
T& Array<T>::operator [](const size_t index) {
    return m_data[index];
}

template <class T>
const T& Array<T>::operator [](const size_t index) const {
    return m_data[index];
}

template <class T>
size_t Array<T>::size() const {
    return m_size;
}

template <class T>
void Array<T>::swap(Array& first, Array& second)
{
    swap(first.m_data, second.m_data);
    swap(first.m_size, second.m_size);
}

template <class T>
Array<T>& Array<T>::operator +(const Array& arr) {
    Array<int> kk(m_size + arr.size());
    for (int i = 0; i < m_size; i++) kk[i] = m_data[i]; 
    for (int i = m_size; i < m_size + arr.size(); i++) kk[i] = arr.m_data[i];
    return kk;
}

template <class T>
void Array<T>::operator +(T value) {
    for (int i = 0; i < m_size; i++) m_data[i] += value;
}

int main()
{
    Array<int> a(10), b, c(b), d = { 1,2,3,4,5 };
    Array<int> abc = { 1,2,3 };
    Array<int> y = d + abc;
    cout << y.size();
    cout << endl;
    d + 3;
    for (const auto x : d) {
        cout << x << ' ';
    }
    return 0;
}