#pragma once

#include <iostream>
using namespace std;

template <class T1, class T2>
class Animal
{
public:
	Animal(T1 name, T2 age)
#if 1
	{
		m_name = name;
		m_age = age;
	}
#endif

	void Show()
#if 1
	{
		cout << "name: " << m_name << ", age: " << m_age <<endl;
	}
#endif

private:
	T1 m_name;
	T2 m_age;
};

