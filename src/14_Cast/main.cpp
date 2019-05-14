#include <iostream>
using namespace std;


//static_cast:һ���ת��
//dynamic_cast:�����ڸ�����֮���ת��
//const_cast:��Ҫ���const��ת��
//reinterpret_cast:������û�й���������֮��

//1.static_cast
void Test1()
{
	int a = 97;	
	char c = static_cast<char>(a); 
	cout << c << endl;

#if 0
	int *p = NULL;
	char *p = static_cast<char *>(p); //ת��һ������ָ�룬����
#endif
}

class Animal{};
class Bird{};
class Cat : public Animal{};

//2.static_cast
void Test2()
{
#if 0
	Bird *p = NULL;
	Animal *ani = static_cast<Animal*> (p); //ת��û�м̳й�ϵ�Ķ���ָ�룬����
#endif
	
	Animal *a1 = NULL;
	Cat *c1 = static_cast<Cat *>(a1); //ת���м̳й�ϵ�Ķ���ָ��(����ָ��ת����ָ��)����ȷ

	Cat *c2 = NULL;
	Animal *a2 = static_cast<Animal *>(c1); //ת���м̳й�ϵ�Ķ���ָ�루����ָ��ת����ָ�룩����ȷ

	Animal a3;
	Animal &a3r = a3; //��ʽת���ã���ȷ
	Cat &c3 = static_cast<Cat &>(a3r); //��ʾת���ã�������ת�����ã�����ȷ 

	Cat c4;
	Cat &c4r = c4; //��ʽת���ã���ȷ
	Animal &a4r = static_cast<Animal &>(c4r); //��ʾת���ã�������ת�����ã�����ȷ 

}

//dynamic_cast��ת�����м̳й�ϵ��ָ��������ã���ת��֮ǰ��Զ������ͽ��м��
void Test3()
{
	//1.��ͨ����ת��
	//int a = 10;
	//char c = dynamic_cast<char>(a); //����

	//2.�Ǽ̳й�ϵָ��
	//Animal *a1 = NULL;
	//Bird *b1 = dynamic_cast<Bird *>(a1);//����

	//3.�̳й�ϵָ��
	//Animal *a2 = NULL;
	//Cat *c2 = dynamic_cast<Cat *>(a2); //����ָ��ת����ָ�룬����ȫ������

	//4.����ָ��ת����ָ��
	Cat *c3 = NULL;
	Animal *a3 = dynamic_cast<Animal *>(c3); //����ָ��ת����ָ�룬��ȫ����ȷ

	//���ۣ�dynamic_castֻ�����ڸ�����ָ�������֮���ת��������ֻ��������ָ��ת���ɸ���ָ�룬�������򲻰�ȫ
}

//const_cast��������ָ�롢���û��߶���ָ��
void Test4()
{
	//1.��ͨ����ת��
	int a = 10;
	const int &b = a;
	int &c = const_cast<int &>(b); //��ȷ

	c = 20;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	//2.ָ��ת��
	const int *p = NULL;
	int *p2 = const_cast<int *>(p); //constת��consy����ȷ

	int *p3 = NULL;
	const int *p4 = const_cast<const int *>(p3); //��constתconst����ȷ

}

//4.reinterpret_cast ����ת��
typedef void(*FUNC1)(int, int);
typedef void(*FUNC2)(int, char );
int add(int a, int b) {
	return a + b;
}

void Test5()
{
	//1.�޹�ָ��ת��
	Bird *b = NULL;
	Animal *a = reinterpret_cast<Animal *>(b); //��ȷ

	//2.����ָ��ת��
	FUNC1 func1 = 0;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1); //��ȷ
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();


	system("pause");
	return 0;
}