#if 0
#include "Animal.h"

template <class T1, class T2>
Animal<T1, T2>::Animal(T1 name, T2 age)
	: m_name(name)
	, m_age(age)
{
	
}

template <class T1, class T2>
void Animal<T1, T2>::Show()
{
	cout << "name: " << m_name << "age: " << m_age <<endl;
}
#endif