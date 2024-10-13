#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iostream>
#include <vector>

template <typename T>
class Vector {
private:
    std::vector<T> data;

public:
    // ���캯��
    Vector() = default;
    Vector(size_t size, const T& value = T());

    // �������캯��
    Vector(const Vector<T>& other);
    // �ƶ����캯��
    Vector(Vector<T>&& other) noexcept;
    // ��������
    ~Vector() = default;

    // ��ֵ�����
    Vector<T>& operator=(const Vector<T>& other);
    Vector<T>& operator=(Vector<T>&& other) noexcept;

    // ��Ա����
    size_t size() const;
    void resize(size_t newSize, const T& value = T());

    // ���������
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    Vector<T> operator+(const Vector<T>& other) const;
    Vector<T>& operator+=(const Vector<T>& other);

    friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
        for (const auto& elem : vec.data) {
            os << elem << " ";
        }
        return os;
    }

    // �쳣������
    class SizeMismatchException {};
    class OutOfBoundsException {};
};

// ���캯��
template <typename T>
Vector<T>::Vector(size_t size, const T& value) : data(size, value) {}

// �������캯��
template <typename T>
Vector<T>::Vector(const Vector<T>& other) : data(other.data) {}

// �ƶ����캯��
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : data(std::move(other.data)) {}

// ��ֵ�����
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
    }
    return *this;
}

// ��Ա����
template <typename T>
size_t Vector<T>::size() const {
    return data.size();
}

template <typename T>
void Vector<T>::resize(size_t newSize, const T& value) {
    data.resize(newSize, value);
}

// ���������
template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= data.size()) throw OutOfBoundsException();
    return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= data.size()) throw OutOfBoundsException();
    return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
    if (data.size() != other.data.size()) throw SizeMismatchException();
    Vector<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] + other[i];
    }
    return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
    if (data.size() != other.data.size()) throw SizeMismatchException();
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other[i];
    }
    return *this;
}

#endif // VECTOR_CLASS_H