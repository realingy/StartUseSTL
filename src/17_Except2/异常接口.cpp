#include <iostream>
using namespace std;

//1.�ú���ֻ���׳�int, float, char �����쳣���׳������ľͱ���
void func() throw(int, float, char) {
	//throw "abc";
	//throw 1; //ֻ���׳�һ���쳣
	throw 1.2;
}

//2.�ú����׳����е��쳣��Ч
void func2() throw() {
	//throw "abc";
	//throw 1; //ֻ���׳�һ���쳣
	throw 1.2;
}

//3.�ú��������׳����е��쳣��Ч
void func3() {
	//throw "abc";
	//throw 1; //ֻ���׳�һ���쳣
	throw 1.2;
}

int main()
{
	try {
		func2();
	}
	catch(char *str) {
		cout << "�ַ����쳣 " << str << endl;
	}
	catch(int e) {
		cout << "�����쳣 " << e << endl;
	}
	catch(...) {
		cout << "�����쳣!" << endl;
	}

	system("pause");
	return 0;
}