#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//如何基于标准异常库写自己的异常类
//1.我们最好是继承标准异常库，因为C++可以抛出任何类型的异常，所以不继承自标准异常库会导致程序的混乱
//2.继承标准异常库的时候，应重载父类的what函数和虚析构函数
//3.栈展开的过程中，要复制异常类型，那么在自定义异常类中要添加拷贝构造

class MyOutOfRange : public exception {
public:
	MyOutOfRange(char *error)
	{
		pError = new char[strlen(error)+1];
		strcpy(pError, error);
	}

	~MyOutOfRange(){
		if(NULL == pError)
		{
			delete [] pError;
		}
	}
	
	virtual const char *what() const {
		return pError;
	}

public:
	char *pError;

};

class Person {
public:
	Person() {
		m_age = 0;
	}
	
	Person(int age) {
		m_age = age;
	}

	void setAge(int age) {
		if(age < 0 || age > 100)
		{
			throw MyOutOfRange("年龄因该在0到100之间！"); //相当于库类out_of_range的作用
		}
		m_age = age;
	}

private:
	int m_age;

};

void Test()
{
	Person p;
	try {
		p.setAge(1000);
	}

	catch(MyOutOfRange &e) {
		cout << e.what() << endl;
	}
}

int main()
{
	Test();

	system("pause");
	return 0;
}