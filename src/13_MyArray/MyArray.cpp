#pragma once

#include <iostream>
using namespace std;

template <class T>
class MyArray {
public:
	//默认构造
	MyArray(int capacity) {
		m_capacity = capacity;
		m_size = 0;
		m_addr = new T[m_capacity];
	}

	//拷贝构造
	MyArray(const MyArray<T> & other)
	{
		m_capacity = other.m_capacity; 
		m_size = other.m_size;
		
		m_addr = new T[m_capacity]; //为类申请新的内存空间
		for(int i = 0; i < m_size; i++)
		{
			//拷贝数据
			m_addr[i] = other.m_addr[i];
		}
	}

	//析构函数
	~MyArray()
	{
		if(NULL != m_addr)
		{
			delete [] m_addr;
		}
	}
	
	//下标运算符重载
	T &operator[](int index)
	{
		return m_addr[index];
	}
	
	//复制运算符重载
	MyArray<T> &operator=(const MyArray<T> &other)
	{
		if(NULL != m_addr)
		{
			delete [] m_addr; //释放原有空间
		}
		
		m_capacity = other.m_capacity; 
		m_size = other.m_size;
		
		m_addr = new T[m_capacity]; //为类申请新的内存空间
		for(int i = 0; i < m_size; i++)
		{
			//拷贝数据
			m_addr[i] = other.m_addr[i];
		}

		return *this;
	}
	
	//尾部添加元素
	void PushBack(T &element)
	{
		if(m_size >= m_capacity)
		{
			return;
		}
	
		//调用拷贝构造函数
		//1. 如果T是某个类，则该类对象必须能够被拷贝
		//2. 容器都是值寓意，而非引用寓意，向容器中放元素，都是放入元素的拷贝，而非元素本身
		//3. 如果元素的成员有指针，注意深拷贝与浅拷贝的关系
		m_addr[m_size] = element;
		m_size++;
	}

	//这个重载的功能是对右值取引用
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
	int m_capacity;	//容量
	int m_size;		//元素个数
	T *m_addr;		//地址
};

void Test()
{
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);	
	marray.PushBack(b);	
	marray.PushBack(c);	
	marray.PushBack(d);

	marray.PushBack(100); //错误，右值不能取引用
	marray.PushBack(200); //C++11标准，可以对右值取引用 见void PushBack(T &&element)
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
