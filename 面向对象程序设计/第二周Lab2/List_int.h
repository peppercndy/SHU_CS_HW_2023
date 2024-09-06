// List_int.h		单向链表结点数据组织形式描述
#ifndef LIST_INT_H
#define LIST_INT_H
#include <iostream>
using namespace std;

struct Node
{
	int data;			// 数据域(虽然这里仅有一个数据，但还是用数据datum的复数形式)
	Node *next;			// 指针域

	//构造函数，类似于C++OOP
	Node(int val) : data(val),next(nullptr){}
};

// 以下为4个函数的函数原型（其定义已完成，见List_int.cpp文件）
ostream& operator<<(ostream& out, const Node* head);
Node* Locate(Node* head, int x, int& num, bool newsearch = false);	// 返回找到的结点地址，"返回"该结点的序号num
int Save(const char* filename, const Node* head);
int Load(const char* filename, Node*& head);
void Create(Node *&head,int n,int *arr);
void ShowList(Node *head);
void Insert(Node *&head,int x);
void Append(Node *head,int x);
void FreeList(Node * &head);
// 请在此补充6个函数（Create，NumNodes，ShowList，Insert，Append，FreeList）的函数原型声明


#endif
