//类模板的static成员
//在生成的每一个模板类中，都有自己的static成员，这些模板类之间的static成员是不一样的
//但是某一个模板类的static成员，就只有一个static成员了

#include <iostream>
using namespace std;

template <class T>
class Test{
public:
	static int a;
};

//static成员类外初始化
template<class T> int Test<T>::a = 0;

int main()
{
	Test<int> p1, p2, p3;
	Test<char> pp1, pp2, pp3;

	p1.a = 10;
	pp1.a = 11;

	cout << p1.a << " " << p2.a << " " << p3.a <<endl; //模板类1有自己的static成员
 	cout << pp1.a << " "<< pp2.a << " " << pp3.a <<endl; //模板类2有自己的static成员

	system("pause");
	return 0;
}


