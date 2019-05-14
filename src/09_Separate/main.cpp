#include <iostream>
using namespace std;

#include "Animal.h"

int main(void)
{
	Animal Person(12);
	cout << "id: " << Person.GetId() << endl;

	system("pause");
	return 0;
}
