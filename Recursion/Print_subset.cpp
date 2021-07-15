/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
12
20
20 12
15
15 12
15 20
15 20 12
*/
/******************************************************************************************************/
#include<iostream>
using namespace std;

void print_substr(int arr[], int size, int ans[], int size2)
{
	if (size == 0)
	{
		for (int i = 0; i < size2; ++i)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	print_substr(arr + 1, size - 1, ans, size2);
	//ans[0] = arr[0]; //wrong method

	int newans[size2 + 1];
	int i;
	for (i = 0; i < size2; i++)
		newans[i] = ans[i];
	newans[i] = arr[0];

	print_substr(arr + 1, size - 1, newans, size2 + 1);

}


void print_substr(int arr[], int size)
{
	int ans[20];
	print_substr(arr, size, ans, 0);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	print_substr(arr, n);

	delete [] arr;
}