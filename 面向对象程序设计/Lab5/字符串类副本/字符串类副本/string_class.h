#pragma once
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

    //����String��������
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

    //��������
    MyString& insert(size_t pos, const MyString& str) ;
    MyString& insert(size_t pos, const char* str)  ;
    MyString& erase(size_t pos, size_t n);
    MyString substring(size_t pos, size_t n) const;

    // �쳣������
<<<<<<< HEAD:Lab4/字符串类副本/字符串类副本/string_class.h
    class OutOfBoundsException {};
};
=======
    class OutOfBoundsException : public std::runtime_error {
    public:
        OutOfBoundsException(const std::string& message)
            : std::runtime_error(message) {}
    };
};


#endif // STRING_CLASS_H
>>>>>>> 116ef2b5ace851157c39810589d9c45ac7d84007:Lab4字符串+向量/string_class.h
