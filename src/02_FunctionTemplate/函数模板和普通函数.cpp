#include <iostream>
using namespace std;

template <class T>
T Add(T a, T b)
{
	cout << "���õ�����ģ��1!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

template <class T1, class T2>
T1 Add(T1 a, T2 b)
{
	cout << "���õ�����ģ��2!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

int Add(int a, char b)
{
	cout << "���õ���ͨ����!" << endl;
	cout << a << endl;
	cout << b << endl;
	return a + b;
}

//1.����ģ�岻�����Զ�����ת���������ϸ������ƥ��
//2.��ͨ���������Զ�����ת��
void Test()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	cout << Add(a,b) << endl;  //a��b������������ͬ
	cout << Add(a,c1) << endl; //����ģ��ʵ��������
	cout << Add(c1,b) << endl; //����ģ��ʵ��������
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

//1.����ģ��������ͨ����һ��������
//2.C++���������ȿ��ǵ�����ͨ����
//3.�������ģ����Բ������õ�ƥ�䣬��ѡ����ģ��
void Test2()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	cout << Sub(a,b) << endl; //ѡ����ͨ����
}

int main()
{
	Test();
//	Test2();

	system("pause");
	return 0;
}