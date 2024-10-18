#include "string_class.h"
#include <cstring>
#include <stdexcept>
#pragma warning(disable : 4996)

// 构造函数
MyString::MyString(const char* str) {
    if (str) {
        len = std::strlen(str);
        data = new char[len + 1];
        std::strcpy(data, str);
    }
    else {
        len = 0;
        data = new char[1];
        data[0] = '\0';
    }
}

// 拷贝构造函数
MyString::MyString(const MyString& other) {
    len = other.len;
    data = new char[len + 1];
    std::strcpy(data, other.data);
}

// 移动构造函数
MyString::MyString(MyString&& other) noexcept : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

// 析构函数
MyString::~MyString() {
    delete[] data;
}

// 赋值运算符
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] data;
        len = other.len;
        data = new char[len + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }
    return *this;
}

// 成员函数
size_t MyString::length() const {
    return len;
}

const char* MyString::c_str() const {
    return data;
}

// 重载运算符
MyString MyString::operator+(const MyString& other) const {
    size_t new_len = len + other.len;
    char* new_data = new char[new_len + 1];
    std::strcpy(new_data, data);
    std::strcat(new_data, other.data);
    MyString result(new_data);
    delete[] new_data;
    return result;
}

MyString& MyString::operator+=(const MyString& other) {
    *this = *this + other;
    return *this;
}

char& MyString::operator[](size_t index) {
    if (index >= len) throw OutOfBoundsException("Index out of bounds");
    return data[index];
}

const char& MyString::operator[](size_t index) const {
    if (index >= len) throw OutOfBoundsException("Index out of bounds");
    return data[index];
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.data;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    char buffer[1000];
    is >> buffer;
    str = MyString(buffer);
    return is;
}

// 关系运算符
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    return std::strcmp(data, other.data) < 0;
}

bool MyString::operator<=(const MyString& other) const {
    return std::strcmp(data, other.data) <= 0;
}

bool MyString::operator>(const MyString& other) const {
    return std::strcmp(data, other.data) > 0;
}

bool MyString::operator>=(const MyString& other) const {
    return std::strcmp(data, other.data) >= 0;
}

//其他方法
MyString &MyString::insert(size_t pos, const char *str)
{
    int n = strlen(data);
    if(pos>n || pos<0)
    throw OutOfBoundsException("position out of bounds");
    char *p = new char[strlen(data)+strlen(str)+1];
    strncpy(p, data,pos );
    p[pos] = '\0';
    strcat(p, str);
    strcat(p, data+pos);
    delete[] data;
    data = p;
    len = strlen(data);
    return *this;
}

MyString & MyString::insert(size_t pos, const MyString& str)
{
    int n = strlen(data);
    if(pos>n || pos<0)
    throw OutOfBoundsException("position out of bounds");
    char *p = new char[strlen(data)+strlen(str.data)+1];
    strncpy(p, data, pos);
    p[pos] = '\0';
    strcat(p , str.data);
    strcat(p, data+pos);
    delete[] data;
    data = p;
    len = strlen(data);
    return *this;
}

MyString & MyString::erase(size_t pos ,size_t n){
    if(pos<0 || pos>=len){
        throw OutOfBoundsException("position out of bounds");
    }
    if(pos+n > len){
        n = len - pos;
    }
    char* p = new char[len - n + 1];
    strncpy(p, data, pos);
    p[pos] = '\0';
    strcat(p, data + pos + n);
    delete[] data;
    data = p;
    len = len-n;
    return *this;
}

MyString MyString::substring(size_t pos, size_t n) const{
    if(pos<0 || pos>len)
        throw OutOfBoundsException("position out of bounds");
    if(pos+n > len)
    {
         n = len - pos;
    }
    char* p = new char[n+1];
    strncpy(p, data+pos, n);
    p[n] = '\0';
    MyString result(p);
    return result;
}