#include <iostream>
#include <string>
using namespace std;

//throw���쳣�������͵ģ����������֡��ַ������������
//catch�쳣��Ҫ�ϸ��ƥ���쳣����

class MyException {
public:
	MyException() {
		cout << "Ĭ�Ϲ��죡" << endl;
	}

	MyException(const MyException &other) {
		cout << "�������죡" << endl;
	}

	~MyException() {
		cout << "����������" << endl;
	}
};

void func()
{
	//throw MyException();
	throw new MyException();
}

void Test1()
{
	try {
		func();
	}
#if 0
	//1.��ͨԪ�أ��쳣������������쳣����
	catch(MyException e) {
		//�����e���׳����쳣�����Ѿ�����ͬһ��������
		cout << "�쳣����: " <<endl;
	}
#endif
#if 0
	//2.���ã�������ÿ������캯�������µ��쳣����
	catch(MyException &e) {
		//�����e���׳����쳣�����Ѿ�����ͬһ��������
		cout << "�쳣����: " <<endl;
	}
#endif
#if 1
	//3.ָ�룬Ҳ���ÿ������죬�����쳣���������Ҫ�ֶ��ͷ��ڴ�
	catch(MyException *e) {
		//�����e���׳����쳣�����Ѿ�����ͬһ��������
		cout << "�쳣����: " <<endl;
		delete e;
	}
#endif
}

int main()
{
	Test1();

	system("pause");
	return 0;
}