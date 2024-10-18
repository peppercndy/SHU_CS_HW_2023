#pragma once
#include <iostream>

class MyString {
private:
    char* data;
    size_t len;

public:
    // ¹¹Ôìº¯Êı
    MyString(const char* str = nullptr);
    // ¿½±´¹¹Ôìº¯Êı
    MyString(const MyString& other);
    // ÒÆ¶¯¹¹Ôìº¯Êı
    MyString(MyString&& other) noexcept;
    // Îö¹¹º¯Êı
    ~MyString();

    // ¸³ÖµÔËËã·û
    //copy
    MyString& operator=(const MyString& other);
    //move
    MyString& operator=(MyString&& other) noexcept;

    //·µ»ØString¶ÔÏóÊôĞÔ
    size_t length() const;
    const char* c_str() const;

    // ÖØÔØÔËËã·û
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
    

    // ¹ØÏµÔËËã·û
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    //ÆäËû·½·¨
    MyString& insert(size_t pos, const MyString& str) ;
    MyString& insert(size_t pos, const char* str)  ;
    MyString& erase(size_t pos, size_t n);
    MyString substring(size_t pos, size_t n) const;

    // Òì³£´¦ÀíÀà
<<<<<<< HEAD:Lab4/å­—ç¬¦ä¸²ç±»å‰¯æœ¬/å­—ç¬¦ä¸²ç±»å‰¯æœ¬/string_class.h
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
>>>>>>> 116ef2b5ace851157c39810589d9c45ac7d84007:Lab4å­—ç¬¦ä¸²+å‘é‡/string_class.h
