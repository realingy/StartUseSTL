#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

//ģ�壺���Ͳ���������д�������������͵Ĵ���
//Ϊ���ñ���������ģ�庯��������ͨ��������Ҫtemplate�ؼ���
template <class T>
void Swap(T &a, T &b) 
{
	T temp = a;
	a = b;
	b = temp;
}

void Test1()
{
	//1.�Զ��Ƶ�
	cout << "�Զ��Ƶ�: " << endl;
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
	//2.��ʾ��ָ��
	cout << "��ʾָ������ģ��: " << endl;
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