#if 1
#include <iostream>
using namespace std;

struct Job {
	char name[40];
	double salary;
	int floor;
};

template <class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//显示具体化
template<> void Swap<Job>(Job &j1, Job &j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(Job &j)
{
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);

	int i = 10, j = 20;
	cout << "i = " << i << "," << "j = " << j << endl;
	Swap(i, j);
	cout << "now i = " << i << "," << "j = " << j << endl;

	Job ing = { "ingy", 73000.60, 7 };
	Job xin = { "xiny", 63000.60, 9 };
	Show(ing);
	Show(xin);

	Swap(ing, xin);

	cout << "after Job swapping:\n";
	Show(ing);
	Show(xin);

	system("pause");
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

template <typename T>
T rAdd(T &a, T &b)
{
	return a + b;
}

int main()
{
	int ival2 = 6;
	double dval2 = 20.3;
	cout << "test:" << rAdd<double>(ival2, dval2) << endl;  //错误

	return 0;
}
#endif

