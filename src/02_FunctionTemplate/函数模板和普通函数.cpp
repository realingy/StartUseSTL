#include <iostream>
using namespace std;

template <class T>
T Add(T a, T b)
{
	cout << "调用到函数模板1!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

template <class T1, class T2>
T1 Add(T1 a, T2 b)
{
	cout << "调用到函数模板2!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

int Add(int a, char b)
{
	cout << "调用到普通函数!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

//1.函数模板不允许自动类型转换，必须严格的类型匹配
//2.普通函数允许自动类型转换
void Test()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	cout << Add(a,b) << endl;  //a和b的数据类型相同
	cout << Add(a,c1) << endl; //函数模板实例化出错
	cout << Add(c1,b) << endl; //函数模板实例化出错
}

template <class T>
T Sub(T a, T b)
{
	cout << "template function!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a - b;
}

template <class T>
int Sub(T a, T b, T c)
{
	cout << "template function!" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return a - b - c;
}

int Sub(int a, int b)
{
	cout << "common function!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a - b;
}

//1.函数模板允许普通函数一样的重载
//2.C++编译器优先考虑调用普通函数
//3.如果函数模板可以产生更好的匹配，则选择函数模板
void Test2()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	cout << Sub(a,b) << endl; //选择普通函数
}

int main()
{
	Test();
//	Test2();

	system("pause");
	return 0;
}