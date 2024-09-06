// List_int.cpp	������ͷ��㣩������������
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "List_int.h"
using namespace std;

// ����Ϊ4�������ĺ����Ķ��壬�亯������������ԭ�ͣ���List_int.h�ļ�

/* ��ʾ��������������� <<��ʹ֮�ܹ�������Node *�����ͽ������
1. ����� << ��˫Ŀ���㣬����Ҫ���������������� cout << a; �У�cout�ǵ�һ��������a�ĵڶ�����������
2. operator<< Ϊ��������������ʽ��������Ϊ��һ���ڶ���������
3. ��һ����ʽ����Ϊ�����Ͳ�����������std���ֿռ��е�ȫ�ֶ���cout����ͬһ���������͡�
   �༴���������£�����out����cout������������out��cout�ı�������
   Ȼ������������cout��ʵ�Ρ������������ļ�������ʵ�Σ���ô�Ϳ���ֱ��������ļ���
4. �ڶ�����ʽ�������ڴ���������׵�ַ��
5. �����ķ���������Ƴɣ����÷���out��������ֵ���أ������ⴴ�����(�豸)���󣬶���ֱ�ӷ��ص�һ�������󶨵����(�豸)����
   �༴�������һ�������� cout����ô������Ҳ���� cout���������ɱ�֤����� << ʵ���������
   ����������ʽ��cout << a << ", " << b ʵ������ (((cout << a) << ", ") << b������(cout << a)����cout��
   �ʿ��Լ���ִ��(cout << ", ")���������cout����һ��ִ�� cout << b���������cout��
*/
ostream& operator<<(ostream& out, const Node* head)// ��������������<<����ʹ���ܹ�ֱ���������<<�����������
{													// ����C++����printf�������������ԭ��֮һ
	for (; head != NULL; head = head->next)
		out << head->data << endl;					// �����ÿ����������ռһ��
	return out;
}

/* ˼����
1. ��ʽ����newsearch��������ʲô��
�𣺿����ظ�ʹ�ô˺�������Ϊ����������static������
2. ��ʽ���� num �к����ã�
�𣺷��غ�����k��ֵ����Ϊnum�����ã������޸ġ�
3. ΪʲôҪ�� p��k��data ��Ƴɾ�̬�ֲ�������
�𣺱���Ч�ʣ���Ϊ��Ҫ��ε��ô˺�������������static������һ���ҹ��ĵط���
4. �ֲ��Զ�ָ����� temp ��������ʲô��
�𣺱����ҵ��������㣬��Ϊ����Ĵ�����Ҫִ����ǰ��һ���Ĳ���
5. �����ķ���ֵ��ʲô����������Ƿ��ҵ����������Ľ��
�𣺷���ֵ������ΪNode�ĵ�ַ��ֻҪ����ֵ����Null(�ȿ�ָ��),���ҵ�
6. ���β�newsearchΪfalse����ʱ�β� x �������ã�ΪʲôҪ������ƣ�
�𣺶���һ�����������������ܴ�������һ�������ļ�����������ˣ���ʱ��Ҫ����ϵ�x��
*/
Node* Locate(Node* head, int x, int& num, bool newsearch)
{
	static Node* p = head;
	static int data = x;			// ���������������ͬ
	static int k = 0;				// ���ͣ�������
	Node* temp;
	if (newsearch)
	{
		p = head;
		data = x;
		k = 0;
	}
	for (; p != NULL && p->data != data; p = p->next, k++)	// �������"��ǰ"������������
		;
	temp = p;
	num = k;
	if (p != NULL)		// ����ҵ����ڷ����ҵ��Ľ���ַ��temp��֮ǰ��p"����"����ǰ��һ����Ϊ������������׼��
	{
		p = p->next;
		k++;
	}
	return temp;
}

/* ��ʾ
1. �õ��ļ����༰����󣨲μ��̲ĵ�14�µ�2�� �ļ�I/O������
2. �˴����ļ�����Ĭ�ϵ��ı��ļ���ʽ��
3. ������������������������(int)��Ҫ���ܽ��� << �� >> ����(OK)��
4. ������ļ��ĸ�ʽҪ�ܹ�ʹLoad������ȷ�ض�ȡ��
*/
int Save(const char* filename, const Node* head)
{
	ofstream outfile(filename);			// ���ļ������ڽ�����д�����У�
	if (outfile.fail())
		return 0;
	int n = 0;							// ���ڼ��������ͱ���
#if(1)									// �� #if(1) �ĳ� #if(0) �Կ�
	const Node* p;						// �������Ϊ��n�ļ������˴�����ֱ���� outfile << head; ȡ������� for ѭ��
	for (p = head; p != NULL; p = p->next, n++)	// ��������������������������������ļ���
		outfile << p->data << endl;
#else
	outfile << head;					// ���� operator<< ����
	n = NumNodes(head);
#endif
	outfile.close();					// �ر��ļ������������е���������д�뵽�ļ��У���һ�����Ҫ��
	return n;
}

int Load(const char* filename, Node*& head)
{
	int n;							// ���ڼ��������ͱ���
	int x;							// ��������������ͬ�ı���
	ifstream infile(filename);		// ���ļ������ڶ�ȡ���е����ݣ�
	if (infile.fail())
		return 0;
	for (n = 0; infile >> x; n++)		// �������ļ��ж�ȡ���ݣ����γ�һ������
		Append(head, x);
	infile.close();					// �ر��ļ�
	return n;
}

// ���ڴ����6��������Create��NumNodes��ShowList��Insert��Append��FreeList���Ķ���

//Create(head, n, array);
/*
struct Node
{
	int data;			// ������(��Ȼ�������һ�����ݣ�������������datum�ĸ�����ʽ)
	Node *next;			// ָ����
};

void Init(Node *&head)					// ����Create������������ŵ�����Ԫ�ش�������
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 5, 2, 5, 8};
	int n = sizeof(array)/sizeof(*array);
	Create(head, n, array);
}

*/
void Create(Node *&head,int n,int *arr){
	for(size_t i=0;i<n;i++){
		Node *node=new Node(arr[i]);
		(*node).next=head;
		head=node ;
	}
}
/*
ShowList(head);
Insert(head, x);
Append(head, x);
FreeList(head);
*/

void ShowList(Node *head){
	if(head==NULL){
		cout<<"ͷ����ǿ�ָ��"<<endl;
	}
	else{
	while(head!=NULL){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
	}
}
void Insert(Node *&head,int x){
	Node *node=new Node(x);
	node->next=head;
	head=node;
}

void Append(Node *head,int x){
	while(head->next!=NULL){
		head=head->next;
	}
	Node *node=new Node(x);
	head->next=node;
}
void FreeList(Node * &head){
	while(head!=NULL){
		Node *temp=head;
		head=head->next;
		delete temp;
	}
}
