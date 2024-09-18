// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

/*****˼��*******
data��AccoutDataʹ��ģ�岻����
����Node��AccoutNode����ʹ��ģ�壨����

template<class T>
class Node{
private:
    T data;
    Node * next;
public:
    Node(const T &data);
} 

ͬ���ĵ���Hero��Accout����ʹ��ģ��

template<class T>
class Accout{
private:
    T *head;
    int num;
}

�����������ڣ�Hero��Accout�ĺ���������һ��������ͬ����
��ʼ������ɾ�Ĳ�֮��Ĳ�����Ȼ����ԵĹ��ܲ�һ��������
���������find�������������Ͳ�һ�������ܲ���Ҳ��һ����
����������ʹ��ģ�壬���˾���Ч�ʸ��͡�
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