#include <iostream>
using namespace std;


//static_cast:一般的转换
//dynamic_cast:适用于父子类之间的转换
//const_cast:主要针对const的转换
//reinterpret_cast:适用于没有关联的数据之间

//1.static_cast
void Test1()
{
	int a = 97;	
	char c = static_cast<char>(a); 
	cout << c << endl;

#if 0
	int *p = NULL;
	char *p = static_cast<char *>(p); //转换一般数据指针，错误
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
	Animal *ani = static_cast<Animal*> (p); //转换没有继承关系的对象指针，出错
#endif
	
	Animal *a1 = NULL;
	Cat *c1 = static_cast<Cat *>(a1); //转换有继承关系的对象指针(父类指针转子类指针)，正确

	Cat *c2 = NULL;
	Animal *a2 = static_cast<Animal *>(c1); //转换有继承关系的对象指针（子类指针转父类指针），正确

	Animal a3;
	Animal &a3r = a3; //隐式转引用，正确
	Cat &c3 = static_cast<Cat &>(a3r); //显示转引用（父引用转子引用），正确 

	Cat c4;
	Cat &c4r = c4; //隐式转引用，正确
	Animal &a4r = static_cast<Animal &>(c4r); //显示转引用（子引用转父引用），正确 

}

//dynamic_cast，转换具有继承关系的指针或者引用，在转换之前会对对象类型进行检查
void Test3()
{
	//1.普通数据转换
	//int a = 10;
	//char c = dynamic_cast<char>(a); //出错

	//2.非继承关系指针
	//Animal *a1 = NULL;
	//Bird *b1 = dynamic_cast<Bird *>(a1);//出错

	//3.继承关系指针
	//Animal *a2 = NULL;
	//Cat *c2 = dynamic_cast<Cat *>(a2); //父类指针转子类指针，不安全，错误

	//4.子类指针转父类指针
	Cat *c3 = NULL;
	Animal *a3 = dynamic_cast<Animal *>(c3); //子类指针转父类指针，安全，正确

	//结论：dynamic_cast只能用于父子类指针或引用之间的转换，而且只能是子类指针转换成父类指针，反过来则不安全
}

//const_cast，适用于指针、引用或者对象指针
void Test4()
{
	//1.普通引用转换
	int a = 10;
	const int &b = a;
	int &c = const_cast<int &>(b); //正确

	c = 20;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	//2.指针转换
	const int *p = NULL;
	int *p2 = const_cast<int *>(p); //const转非consy，正确

	int *p3 = NULL;
	const int *p4 = const_cast<const int *>(p3); //非const转const，正确

}

//4.reinterpret_cast 任意转换
typedef void(*FUNC1)(int, int);
typedef void(*FUNC2)(int, char );
int add(int a, int b) {
	return a + b;
}

void Test5()
{
	//1.无关指针转换
	Bird *b = NULL;
	Animal *a = reinterpret_cast<Animal *>(b); //正确

	//2.函数指针转换
	FUNC1 func1 = 0;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1); //正确
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