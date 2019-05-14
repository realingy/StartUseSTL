#pragma once
#include <iostream>
using namespace std;

template <class T>
class Animal
{
public:
	//template <class T>
	//friend ostream & operator << (ostream & os, Animal<T> &p);
	
	template <class T>
	friend void PrintAnimal(Animal<T> &p);

	Animal(T id, T age) {
		m_id = id;
		m_age = age;
	}

	void Show() {
		cout << "age: " << m_age << ", id: " << m_id <<endl;
	}

private:
	T m_id;
	T m_age;
};

//类外部实现功能
//1.友元方法重载左移运算符
template <class T>
ostream & operator << (ostream & os, Animal<T> &p)
{
	os << "age: " << p.m_age << ", id" << p.m_id << endl;
	return os;
}

//类外部实现功能
//2.友元方法普通函数
template <class T>
void PrintAnimal(Animal<T> &p)
{
	cout << "age: " << p.m_age << ", id" << p.m_id << endl;
}

int main()
{
	Animal<int> Cat(12, 78);
	//Cat.Show();		//1.类的成员输出信息
	//cout << Cat;		//2.类的友元方法重载左移运算符
	PrintAnimal(Cat); //3.类的友元普通函数

	system("pause");
	return 0;
}