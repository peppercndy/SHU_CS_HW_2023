// List_int.h		�����������������֯��ʽ����
#ifndef LIST_INT_H
#define LIST_INT_H
#include <iostream>
using namespace std;

struct Node
{
	int data;			// ������(��Ȼ�������һ�����ݣ�������������datum�ĸ�����ʽ)
	Node *next;			// ָ����

	//���캯����������C++OOP
	Node(int val) : data(val),next(nullptr){}
};

// ����Ϊ4�������ĺ���ԭ�ͣ��䶨������ɣ���List_int.cpp�ļ���
ostream& operator<<(ostream& out, const Node* head);
Node* Locate(Node* head, int x, int& num, bool newsearch = false);	// �����ҵ��Ľ���ַ��"����"�ý������num
int Save(const char* filename, const Node* head);
int Load(const char* filename, Node*& head);
void Create(Node *&head,int n,int *arr);
void ShowList(Node *head);
Node * Insert(Node *&head,int x);
Node * Append(Node *head,int x);
void FreeList(Node * &head);
int NumNodes(Node *head);
// ���ڴ˲���6��������Create��NumNodes��ShowList��Insert��Append��FreeList���ĺ���ԭ������


#endif
