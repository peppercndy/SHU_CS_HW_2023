#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>

class MyString {
private:
    char* data;
    size_t len;

public:
    // ���캯��
    MyString(const char* str = nullptr);
    // �������캯��
    MyString(const MyString& other);
    // �ƶ����캯��
    MyString(MyString&& other) noexcept;
    // ��������
    ~MyString();

    // ��ֵ�����
    //copy
    MyString& operator=(const MyString& other);
    //move
    MyString& operator=(MyString&& other) noexcept;

    // ��Ա����
    size_t length() const;
    const char* c_str() const;

    // ���������
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    // ��ϵ�����
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // �쳣������
    class OutOfBoundsException {};
};

#endif // STRING_CLASS_H
