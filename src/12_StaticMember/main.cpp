//��ģ���static��Ա
//�����ɵ�ÿһ��ģ�����У������Լ���static��Ա����Щģ����֮���static��Ա�ǲ�һ����
//����ĳһ��ģ�����static��Ա����ֻ��һ��static��Ա��

#include <iostream>
using namespace std;

template <class T>
class Test{
public:
	static int a;
};

//static��Ա�����ʼ��
template<class T> int Test<T>::a = 0;

int main()
{
	Test<int> p1, p2, p3;
	Test<char> pp1, pp2, pp3;

	p1.a = 10;
	pp1.a = 11;

	cout << p1.a << " " << p2.a << " " << p3.a <<endl; //ģ����1���Լ���static��Ա
 	cout << pp1.a << " "<< pp2.a << " " << pp3.a <<endl; //ģ����2���Լ���static��Ա

	system("pause");
	return 0;
}


