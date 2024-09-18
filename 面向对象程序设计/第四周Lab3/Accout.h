// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

/*****思考*******
data与AccoutData使用模板不方便
但是Node与AccoutNode可以使用模板（？）

template<class T>
class Node{
private:
    T data;
    Node * next;
public:
    Node(const T &data);
} 

同样的道理，Hero与Accout可以使用模板

template<class T>
class Accout{
private:
    T *head;
    int num;
}

不过问题在于，Hero与Accout的函数方法不一样，尽管同样是
初始化与增删改查之类的操作，然而针对的功能不一样，例如
两个对象的find函数，返回类型不一样，接受参数也不一样。
所以这两个使用模板，本人觉得效率更低。
******************/
struct Data {
    std::string name;
    int stones;
};

class Node {
private:
    Data data;
    Node* next;
public:
    Node(const Data& data);
    friend class Hero;
};

class Hero {
private:
    Node* head;
    int num;
public:
    Hero(int n, const Data* datas);
    void showList();
    void freeList();
    void append(const Data& data);
    bool find(const std::string& name);
    int heronums() const;
};

struct AccoutData {
    Hero link;
    int UID;
};

class AccoutNode {
private:
    AccoutData data;
    AccoutNode* next;
public:
    AccoutNode(const AccoutData& data);
    friend class Accout;
};

class Accout {
private:
    AccoutNode* head;
    int num;
public:
    Accout(AccoutData* arr, int n);
    void showAccoutList();
    void freeLink();
    void append(const AccoutNode& node);
    Hero find(const int& UID);
    void deleteAccout(const int& UID);
    int accoutnums() const;
};

#endif // ACCOUNT_H