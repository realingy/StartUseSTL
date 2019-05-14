#include "Animal.h"
#include <string>

int main()
{
	Animal<string , int> Cat("tom", 78);
	Cat.Show();
 
	system("pause");
	return 0;
}