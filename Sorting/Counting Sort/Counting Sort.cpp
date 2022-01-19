#include <iostream>

/*
Counting Sort
O(N)
require data's range
under that specific condition very efficient
*/

using namespace std;

int main()
{
	int count[5]{ 0 };
	int arr[] = { 1, 3, 5, 1, 2, 3, 4, 5, 3, 1, 1, 3, 2, 2, 4, 1, 5,3, 1, 1, 1, 2, 2 ,1 ,5}; // 25 ele
	for (int i = 0; i < 25; i++) {
		count[arr[i]-1]++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i+1 << ' ';
		}
	}
}