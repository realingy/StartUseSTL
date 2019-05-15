#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//��λ��ڱ�׼�쳣��д�Լ����쳣��
//1.��������Ǽ̳б�׼�쳣�⣬��ΪC++�����׳��κ����͵��쳣�����Բ��̳��Ա�׼�쳣��ᵼ�³���Ļ���
//2.�̳б�׼�쳣���ʱ��Ӧ���ظ����what����������������
//3.ջչ���Ĺ����У�Ҫ�����쳣���ͣ���ô���Զ����쳣����Ҫ��ӿ�������

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
			throw MyOutOfRange("���������0��100֮�䣡"); //�൱�ڿ���out_of_range������
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