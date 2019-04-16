#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//模板：类型参数化，编写独立于数据类型的代码
//为了让编译器区分模板函数还是普通函数，需要template关键字
template <class T>
void Swap(T &a, T &b) 
{
	T temp = a;
	a = b;
	b = temp;
}

void Test1()
{
	//1.自动推导
	cout << "自动推导: " << endl;
	int a = 10;
	int b = 20;
	cout << "a: " << a << ", b: " << b <<endl;
	Swap(a,b);
	cout << "a: " << a << ", b: " << b <<endl;

	double da = 1.13;
	double db = 1.14;
	cout << "da: " << da << ", db: " << db <<endl;
	Swap(da,db);
	cout << "da: " << da << ", db: " << db <<endl;

} 

void Test2() {
	//2.显示的指定
	cout << "显示指定函数模板: " << endl;
	double da = 1.13;
	double db = 1.14;
	cout << "da: " << da << ", db: " << db <<endl;
	Swap<double>(da,db);
	cout << "da: " << da << ", db: " << db <<endl;
}

int main()
{
	Test1();
	Test2();
	 
	system("pause");
	return 0;
}