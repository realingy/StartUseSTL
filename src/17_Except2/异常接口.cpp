#include <iostream>
using namespace std;

//1.该函数只能抛出int, float, char 三种异常，抛出其他的就报错
void func() throw(int, float, char) {
	//throw "abc";
	//throw 1; //只能抛出一个异常
	throw 1.2;
}

//2.该函数抛出所有的异常无效
void func2() throw() {
	//throw "abc";
	//throw 1; //只能抛出一个异常
	throw 1.2;
}

//3.该函数可以抛出所有的异常无效
void func3() {
	//throw "abc";
	//throw 1; //只能抛出一个异常
	throw 1.2;
}

int main()
{
	try {
		func2();
	}
	catch(char *str) {
		cout << "字符串异常 " << str << endl;
	}
	catch(int e) {
		cout << "整数异常 " << e << endl;
	}
	catch(...) {
		cout << "捕获到异常!" << endl;
	}

	system("pause");
	return 0;
}