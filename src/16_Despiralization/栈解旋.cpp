/******************************************************************************
	
	栈解旋

	从进入try块起，到异常被抛出之前，期间在栈上构造的所有的对象，
	都会在异常抛出时被自动析构，析构的顺序与构造的顺序相反，这一过程成为栈解旋

******************************************************************************/

#include <iostream>
using namespace std;

class AA {
public:
	AA() {
		cout << "对象构造！" << endl;
	}

	~AA() {
		cout << "对象析构！" << endl;
	}
};

int divide(int a, int b)
{
	cout << "divide " << endl;
	AA a1, a2; //构造对象
	if(!b) {
		cout << "抛出异常，析构所有的对象" << endl;
		throw b;//抛出异常，析构对象
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
		cout << "异常捕获！ " << e << endl;
	}
}

int main()
{
	Test1();

	system("pause");
	return 0;
}
