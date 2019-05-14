#include <iostream>

using namespace std;

template <class T>
void Sort(T *arr, int len)
{
	for(int i = 0; i < len; i++) {
		for(int j = i; j < len; j++) {
			if(arr[i] < arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
 			}
		}
	}
}

template <class T>
void PrintArray(T *arr, int len)
{
	for(int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() 
{
	//int数组
	int arr[] = {2,6,1,8,9,2};

	int len = sizeof(arr)/sizeof(int);
	PrintArray(arr, len);
	Sort(arr, len);
	PrintArray(arr, len);

	//char数组
	char chArr[] = {'d', 't', 'x', 'q', 'i', 'p'};

	int len2 = sizeof(chArr)/sizeof(char);
	PrintArray(chArr, len2);
	Sort(chArr, len2);
	PrintArray(chArr, len2);

	system("pause");
	return 0;
}