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

//���ⲿʵ�ֹ���
//1.��Ԫ�����������������
template <class T>
ostream & operator << (ostream & os, Animal<T> &p)
{
	os << "age: " << p.m_age << ", id" << p.m_id << endl;
	return os;
}

//���ⲿʵ�ֹ���
//2.��Ԫ������ͨ����
template <class T>
void PrintAnimal(Animal<T> &p)
{
	cout << "age: " << p.m_age << ", id" << p.m_id << endl;
}

int main()
{
	Animal<int> Cat(12, 78);
	//Cat.Show();		//1.��ĳ�Ա�����Ϣ
	//cout << Cat;		//2.�����Ԫ�����������������
	PrintAnimal(Cat); //3.�����Ԫ��ͨ����

	system("pause");
	return 0;
}