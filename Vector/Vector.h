/**
 * @file Vector.h
 * @brief File header cho lớp template Vector - mảng động tổng quát
 * @author Nguyen The Quan (24127514)
 * @date 2025
 * @version 1.0
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

/**
 * @class Vector
 * @brief Lớp template mảng động tổng quát
 * @tparam T Kiểu dữ liệu của các phần tử trong vector
 * 
 * Lớp Vector cung cấp:
 * - Mảng động có thể thay đổi kích thước
 * - Quản lý bộ nhớ tự động
 * - Các thao tác cơ bản: thêm, truy cập, xóa
 * - Copy constructor và assignment operator
 */
template <typename T>
class Vector {
private:
    /**
     * @brief Dung lượng ban đầu của vector
     */
    static const int INITIAL_CAPACITY = 50;
    /**
     * @brief Bước tăng dung lượng khi cần mở rộng
     */
    static const int STEP = 50;
private:
    /**
     * @brief Con trỏ trỏ đến mảng chứa các phần tử
     */
    T* _items = nullptr;
    /**
     * @brief Dung lượng hiện tại của vector
     */
    int _capacity = 0;
    /**
     * @brief Số lượng phần tử hiện có trong vector
     */
    int _size = 0;
private: 
    /**
     * @brief Thay đổi kích thước mảng khi cần thiết
     */
    void _resize();
    /**
     * @brief Sao chép sâu từ vector khác
     * @param other Vector nguồn cần sao chép
     */
    void _deepCopy(const Vector<T>& other);
public:
    /**
     * @brief Constructor mặc định
     */
    Vector();
    
    /**
     * @brief Copy constructor
     * @param other Vector nguồn cần sao chép
     */
    Vector(const Vector<T>& other);
    
    /**
     * @brief Assignment operator
     * @param other Vector nguồn cần gán
     * @return Tham chiếu đến vector hiện tại
     */
    Vector& operator=(const Vector<T>& other);
    
    /**
     * @brief Destructor
     */
    ~Vector();
public:
    /**
     * @brief Thêm phần tử vào cuối vector
     * @param item Phần tử cần thêm
     */
    void push_back(const T& item);
    
    /**
     * @brief Truy cập phần tử theo chỉ số (có thể thay đổi)
     * @param index Chỉ số của phần tử
     * @return Tham chiếu đến phần tử
     */
    T& operator[](int index);
    
    /**
     * @brief Truy cập phần tử theo chỉ số (chỉ đọc)
     * @param index Chỉ số của phần tử
     * @return Tham chiếu const đến phần tử
     */
    const T& operator[](int index) const;
    
    /**
     * @brief Lấy số lượng phần tử trong vector
     * @return Số lượng phần tử
     */
    int size() const;
    
    /**
     * @brief Kiểm tra vector có rỗng không
     * @return true nếu vector rỗng, false nếu ngược lại
     */
    bool isEmpty() const;
    
    /**
     * @brief Xóa tất cả phần tử trong vector
     */
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