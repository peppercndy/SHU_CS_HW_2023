#include "string_class.h"
#include "vector_class.h"
#include <iostream>
using namespace std;

void testMyString() {
    MyString s1("hello world");
    MyString s2("goodbye");    /*try{
    //char a = s1[100];
    vector<int> v1(5,10);
    Vector<int> v2(4,20);
    Vector<int> v3 = v1+v2;
    cout << v3 << endl;
    }
    catch(MyString::OutOfBoundsException &e)
    {
        cout << e.what() << endl;
    }
    catch(Vector<int>::SizeMismatchException &)
    {
        cout << "Size Mismatch Exception" << endl;
    }*/
   //MyString s3 = s1.insert(-1, "goodbye");
    try{MyString s3 = s1.insert(-1, s2);
    cout << s3 << endl;
    }
    catch(MyString::OutOfBoundsException &e)
    {
        cout << e.what() << endl;
    }
}

void testMyVector() {
    Vector<int> v1(5, 10);
    Vector<int> v2(4, 20);
    Vector<int> v3 = v1 + v2;
    cout << v3 << endl;
}

int main()
{
    testVector();
    return 0;
}