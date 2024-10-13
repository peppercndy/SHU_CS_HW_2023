#ifndef STRING_CLASS_H
#define STRING_CLASS_H

#include <iostream>

class MyString {
private:
    char* data;
    size_t len;

public:
    // 构造函数
    MyString(const char* str = nullptr);
    // 拷贝构造函数
    MyString(const MyString& other);
    // 移动构造函数
    MyString(MyString&& other) noexcept;
    // 析构函数
    ~MyString();

    // 赋值运算符
    //copy
    MyString& operator=(const MyString& other);
    //move
    MyString& operator=(MyString&& other) noexcept;

    // 成员函数
    size_t length() const;
    const char* c_str() const;

    // 重载运算符
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

    // 关系运算符
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    // 异常处理类
    class OutOfBoundsException {};
};

#endif // STRING_CLASS_H
