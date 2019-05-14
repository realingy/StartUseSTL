#include <iostream>
using namespace std;

//1.��ģ��������ͨ��
//2.��ģ��������ģ��

template <class T>
class Animal {
public:
	Animal()
	{
		m_age = 0;
	}

	Animal(T id, T age)
	{
		m_id = id;
		m_age = age;
	}
	
	void Print() {
		cout << m_age <<  "��Ķ��";
	}

private:
	T m_age;
	T m_id;
};

//1.������ͨ��ʱ����ָ����ģ�����������
class Cat : public Animal<int> {
	Cat() {
	
	}
};

//2.����ģ����ʱ���Բ�ָ�������������
//������Ҫ����ģ��������ʱ�򣬱���ʹ�����������������ָ���������ģ����������
template<class T>
class Dog : public Animal<T> {
public:
	Dog() {}
};

int main(void)
{
	cout << "��ģ����������" << endl;

	system("pause");
	return 0;
}
