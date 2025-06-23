#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    static const int INITIAL_CAPACITY = 50;
    static const int STEP = 50;
private:
    T* _items = nullptr;
    int _capacity = 0;
    int _size = 0;
private: 
    void _resize();
    void _deepCopy(const Vector<T>& other);
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector& operator=(const Vector<T>& other);
    ~Vector();
public:
    void push_back(const T& item);
    T& operator[](int index);
    const T& operator[](int index) const;
    int size() const;
    bool isEmpty() const;
    void clear();
};

// Template implementations
template<typename T>
void Vector<T>::_resize() {
    _capacity += STEP;
    T* newItems = new T[_capacity];
    for (int i = 0; i < _size; ++i) {
        newItems[i] = _items[i];
    }
    delete[] _items;
    _items = newItems;
}

template<typename T>
void Vector<T>::_deepCopy(const Vector<T>& other) {
    _capacity = other._capacity;
    _size = other._size;
    _items = new T[_capacity];
    for (int i = 0; i < _size; ++i) {
        _items[i] = other._items[i];
    }
}

template<typename T>
Vector<T>::Vector() {
    _capacity = INITIAL_CAPACITY;
    _items = new T[_capacity];
    _size = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
    _deepCopy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] _items; // Free existing memory
        _deepCopy(other); // Copy from other vector
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] _items; 
}

template<typename T>
void Vector<T>::push_back(const T& item) {
    if (_size == _capacity) {
        _resize(); 
    }
    _items[_size] = item; 
    ++_size; 
}

template<typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= _size) {
        std::cerr << "Lỗi: Chỉ số ngoài phạm vi của Vector.\n";
        exit(1);
    }
    return _items[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= _size) {
        std::cerr << "Lỗi: Chỉ số ngoài phạm vi của Vector.\n";
        exit(1);
    }
    return _items[index];
}

template<typename T>
int Vector<T>::size() const {
    return _size;
}

template<typename T>
bool Vector<T>::isEmpty() const {
    if (_size == 0) {
        return true;
    }
    return false;
}

template<typename T>
void Vector<T>::clear() {
    delete[] _items;
    _capacity = INITIAL_CAPACITY;
    _items = new T[_capacity];
    _size = 0;
}

#endif // VECTOR_H