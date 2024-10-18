#include"vector_class.h"

int main()
{
	int chiose = 0;
	show();
	while (true)
	{
		cout << "输入你的需求" << endl;
		cin >> chiose;
		switch (chiose)
		{
		case 0:
			exitsystem();
			break;
		case 1:
			testVectorInitialization();
			break;
		case 2:
			testCopyAndMove();
			break;
		case 3:
			testAssignment();
			break;
		case 4:
			testIndexing();
			break;
		case 5:
			testArithmeticOperations();
			break;
		case 6:
			testExceptions();
			break;
		default:
			system("cls");
			break;
		}
	}
	cout << "测试完成" << endl;
}
