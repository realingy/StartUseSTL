/******************************************************************************
	
	ջ����

	�ӽ���try���𣬵��쳣���׳�֮ǰ���ڼ���ջ�Ϲ�������еĶ���
	�������쳣�׳�ʱ���Զ�������������˳���빹���˳���෴����һ���̳�Ϊջ����

******************************************************************************/

#include <iostream>
using namespace std;

class AA {
public:
	AA() {
		cout << "�����죡" << endl;
	}

	~AA() {
		cout << "����������" << endl;
	}
};

int divide(int a, int b)
{
	cout << "divide " << endl;
	AA a1, a2; //�������
	if(!b) {
		cout << "�׳��쳣���������еĶ���" << endl;
		throw b;//�׳��쳣����������
	}
	return a / b;
}

void Test1()
{
	cout << "Test" << endl;
	try {
		divide(10, 0); //
	}
	catch(int e) {
		cout << "�쳣���� " << e << endl;
	}
}

int main()
{
	Test1();

	system("pause");
	return 0;
}
