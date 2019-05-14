#include <iostream>
using namespace std;

//1.类模板派生普通类
//2.类模板派生类模板

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
		cout << m_age <<  "岁的动物！";
	}

private:
	T m_age;
	T m_id;
};

//1.派生普通类时必须指定类模板的数据类型
class Cat : public Animal<int> {
	Cat() {
	
	}
};

//2.派生模板类时可以不指父类的数据类型
//但是需要用类模板派生的时候，必须使用子类的数据类型来指定父类的类模板数据类型
template<class T>
class Dog : public Animal<T> {
public:
	Dog() {}
};

int main(void)
{
	cout << "类模板派生规则！" << endl;

	system("pause");
	return 0;
}
