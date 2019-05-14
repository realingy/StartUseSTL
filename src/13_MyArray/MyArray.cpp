#pragma once

#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
	//Ĭ�Ϲ���
	MyArray(int capacity) {
		m_capacity = capacity;
		m_size = 0;
		m_addr = new T[m_capacity];
	}

	//��������
	MyArray(const MyArray<T> & other)
	{
		m_capacity = other.m_capacity; 
		m_size = other.m_size;
		
		m_addr = new T[m_capacity]; //Ϊ�������µ��ڴ�ռ�
		for(int i = 0; i < m_size; i++)
		{
			//��������
			m_addr[i] = other.m_addr[i];
		}
	}

	//��������
	~MyArray()
	{
		if(NULL != m_addr)
		{
			delete [] m_addr;
		}
	}
	
	//�±����������
	T &operator[](int index)
	{
		return m_addr[index];
	}
	
	//�������������
	MyArray<T> &operator=(const MyArray<T> &other)
	{
		if(NULL != m_addr)
		{
			delete [] m_addr; //�ͷ�ԭ�пռ�
		}
		
		m_capacity = other.m_capacity; 
		m_size = other.m_size;
		
		m_addr = new T[m_capacity]; //Ϊ�������µ��ڴ�ռ�
		for(int i = 0; i < m_size; i++)
		{
			//��������
			m_addr[i] = other.m_addr[i];
		}

		return *this;
	}
	
	//β�����Ԫ��
	void PushBack(T &element)
	{
		if(m_size >= m_capacity)
		{
			return;
		}
	
		//���ÿ������캯��
		//1. ���T��ĳ���࣬������������ܹ�������
		//2. ��������ֵԢ�⣬��������Ԣ�⣬�������з�Ԫ�أ����Ƿ���Ԫ�صĿ���������Ԫ�ر���
		//3. ���Ԫ�صĳ�Ա��ָ�룬ע�������ǳ�����Ĺ�ϵ
		m_addr[m_size] = element;
		m_size++;
	}

	//������صĹ����Ƕ���ֵȡ����
	void PushBack(T &&element)
	{
		if(m_size >= m_capacity)
		{
			return;
		}
		
		m_addr[m_size] = element;
		m_size++;
	}

	int GetSize()
	{
		return m_size;
	}

private:
	int m_capacity;	//����
	int m_size;		//Ԫ�ظ���
	T *m_addr;		//��ַ
};

void Test()
{
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);	
	marray.PushBack(b);	
	marray.PushBack(c);	
	marray.PushBack(d);

	marray.PushBack(100); //������ֵ����ȡ����
	marray.PushBack(200); //C++11��׼�����Զ���ֵȡ���� ��void PushBack(T &&element)
	marray.PushBack(300);

	for(int i = 0; i < marray.GetSize(); i++)
	{
		cout << marray[i] << " ";
	}
	cout << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}
