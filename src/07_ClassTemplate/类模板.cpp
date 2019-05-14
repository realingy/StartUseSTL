#include <iostream>

using namespace std;

template <class T>
class Person {
public:
	Person(T id, T age) {
		m_id = id;
		m_age = age;
	}

	void Show() {
		cout << "id: " << m_id << ", age: " << m_age <<endl;
	}

private:
	T m_id;
	T m_age;
};

int main()
{
	Person<int> p(1001, 25);
	p.Show();

	system("pause");
	return 0;

}