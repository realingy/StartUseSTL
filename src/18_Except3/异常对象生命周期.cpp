#include <iostream>
#include <string>
using namespace std;

//throw的异常是有类型的，可以是数字、字符串或者类对象
//catch异常需要严格的匹配异常类型

class MyException {
public:
	MyException() {
		cout << "默认构造！" << endl;
	}

	MyException(const MyException &other) {
		cout << "拷贝构造！" << endl;
	}

	~MyException() {
		cout << "析构函数！" << endl;
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
	//1.普通元素，异常处理完后析构异常对象
	catch(MyException e) {
		//这里的e和抛出的异常对象已经不是同一个对象了
		cout << "异常捕获: " <<endl;
	}
#endif
#if 0
	//2.引用，不会调用拷贝构造函数构造新的异常对象
	catch(MyException &e) {
		//这里的e和抛出的异常对象已经不是同一个对象了
		cout << "异常捕获: " <<endl;
	}
#endif
#if 1
	//3.指针，也不用拷贝构造，而且异常处理完后需要手动释放内存
	catch(MyException *e) {
		//这里的e和抛出的异常对象已经不是同一个对象了
		cout << "异常捕获: " <<endl;
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