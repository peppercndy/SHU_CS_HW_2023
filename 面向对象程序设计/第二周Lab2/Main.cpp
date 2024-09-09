// Main.cpp					���ǲ��Գ��������޸�
#define _CRT_SECURE_NO_WARNINGS
#include "List_int.h"
#include <cstring>
#include <conio.h>

int Pos(char ch, const char *str) // ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
		if (ch == str[i])
			return i;
	return -1;
}

int Choice(const char *prompt, const char *options = "") // �����ʾ��Ϣprompt������ѡ����ַ������ء�
{
	int key;
	cout << prompt << "{";
	for (int i = 0; options[i] != '\0'; i++)
	{
		if (' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127) // ѡ��options�еĿɴ�ӡ�ַ�
			cout << options[i] << ' ';
		else // ѡ��options�еĲ��ֿ����ַ�
		{
			switch (options[i])
			{
			case '\t':
				cout << "[Tab] ";
				break; // ѡ���е�Tab�ַ�'\t'����ASCII����9��
			case '\x1b':
				cout << "[Esc] ";
				break; // ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
			case ' ':
				cout << "[Space] ";
				break; // ѡ���еĿո��ַ�' '����ASCII����32��
			}
		}
	}
	cout << "\b}: "; // '\b'�˸�����һ��������һ�����
	do
	{
		key = _getch();
	} while (options[0] != '\0' && Pos(key, options) < 0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
	cout << endl;
	return key;
}

void Init(Node *&head) // ����Create������������ŵ�����Ԫ�ش�������
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 5, 2, 5, 8};
	int n = sizeof(array) / sizeof(*array);
	Create(head, n, array);
}

void Find(Node *head, int x) // ����Locate�����ر�ע��"����/��������"
{
	Node *p;
	int n = 0, num;
	p = Locate(head, x, num, true);
	while (p != NULL)
	{
		cout << "�ҵ��� " << num << " ���(��Ŵ�0��ʼ)��\t" << p->data << endl;
		n++;
		p = Locate(head, x, num);
	}
	cout << "\t���ҵ� " << n << " ����㣬����������" << endl;
}

int main()
{
	Node *head = NULL; // ����һ������������
	char filename[80] = "data_int.txt";
	int x; // ��������������ͬ�ı���
	int n, key, yn;

	Init(head); // ����Create
	while (true)
	{
		cout << "\n========== MENU ==========" << endl;
		cout << "  1 ---- �� �� �� �� (P)" << endl;
		cout << "  2 ---- �� �� �� �� (I)" << endl;
		cout << "  3 ---- ׷ �� �� �� (A)" << endl;
		cout << "  4 ---- �� ѯ �� �� (S)" << endl;
		cout << "  5 ---- ����д���ļ�(W)" << endl;
		cout << "  6 ---- ��ȡ�����ļ�(R)" << endl;
		cout << "  7 ---- �ͷ����н��(F)" << endl;
		cout << "  8 ---- ���������(N)" << endl;
		cout << "  0 ---- ��      ��(ESC)" << endl;
		cout << "==========================" << endl;
		key = Choice("��ѡ��", "01234567\x1bpPiIaAsSwWrRfF");
		cout << "\n\n";
		if (key == 27 || key == '0') // '\x1b'����27��ָESC��
			break;
		switch (key)
		{
		case '1':
		case 'p':
		case 'P':
			cout << "��һ�ָ�ʽ���" << endl;
			ShowList(head);
			cout << "\n�ڶ��ָ�ʽ���" << endl;
			cout << head << endl;
			break;
		case '2':
		case 'i':
		case 'I':
			cout << "����һ����㵽�����׽��ǰ������������������(int): ";
			cin >> x;
			//cout<<head->data<<endl;
			Insert(head, x);
			break;
		case '3':
		case 'a':
		case 'A':
			cout << "׷��һ�����(��β����)������������������(int): ";
			cin >> x;
			Append(head, x);
			break;
		case '4':
		case 's':
		case 'S':
			cout << "�������������ݲ�ѯ�����������ѯ������(int): ";
			cin >> x;
			Find(head, x);
			break;
		case '5':
		case 'w':
		case 'W':
			n = Save(filename, head);
			cout << "�� " << n << " ����������д�� "
				 << filename << " �ļ���" << endl;
			break;
		case '6':
		case 'r':
		case 'R':
			cout << "��ȡ�����ļ����Ƿ����ͷ����е����н��(y/[N])? ";
			yn = _getche();
			if (yn == 'y' || yn == 'Y')
				FreeList(head);
			n = Load(filename, head);
			cout << "�� " << filename << " �ļ��ж�ȡ "
				 << n << " �����ݡ�" << endl;
			break;
		case '7':
		case 'f':
		case 'F':
			cout << "�ͷ����н�㡣�Ƿ����(y/[N])? ";
			yn = _getche();
			if (yn == 'y' || yn == 'Y') // Ĭ�� No
				FreeList(head);
			break;
		/*
		case '8':
		case 'n':
		case 'N':
			int number=NumNodes(head);
			cout<<"�������ܹ��� "<<number<<" �����"<<endl;
			break;
			*/
		}
		
	}
	if (head != NULL)
	{
		cout << "\n�����˳��������������Ƿ����([Y]/n)? ";
		yn = _getche();
		if (yn != 'n' && yn != 'N') // Ĭ�� Yes
		{
			filename[Pos('.', filename)] = '\0'; // ȥ���ļ���չ��.txt
			strcat(filename, "(1).txt");		 // ƴ�ӳ��µ��ļ���
			n = Save(filename, head);
			cout << "\n�ѽ� " << n << " ���������ݴ��� " << filename << " �ļ���" << endl;
		}
	}
	cout << "\n�ͷ����н�㣬���ز���ϵͳ��" << endl;
	FreeList(head);
	return 0;
}
