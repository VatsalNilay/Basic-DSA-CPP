/*
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.

Groups can be made with any set of elements, i.e. elements need not to be continuous.
And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.

Note : You will get marks only if all the test cases are passed.

Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false
Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2
Sample Output 1 :
false

Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
*/

/****************************************************************************************************/
#include<iostream>
using namespace std;

bool splitArray(int* arr, int size, int currIndex, int lsum, int rsum)
{
	if (currIndex == size)
		return lsum == rsum;

	if (arr[currIndex] % 5 == 0)
	{
		lsum += arr[currIndex];
		return splitArray(arr, size, currIndex + 1, lsum, rsum);
	}
	else if (arr[currIndex] % 3 == 0)
	{
		rsum += arr[currIndex];
		return splitArray(arr, size, currIndex + 1, lsum, rsum);
	}
	else
	{
		bool leftAns = splitArray(arr, size, currIndex + 1, lsum + arr[currIndex], rsum);
		bool rightAns = splitArray(arr, size, currIndex + 1, lsum, arr[currIndex] + rsum);

		return leftAns || rightAns;
	}
	// return splitArray(arr, size, currIndex + 1, lsum, rsum);
}


bool splitArray(int* arr, int size)
{
	return splitArray(arr, size, 0, 0, 0);
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; ++i)
		cin >> arr[i];

	if (splitArray(arr, size))
		cout << "True" << endl;
	else
		cout << "False" << endl;

	// for (int i = 0; i < size; ++i)
	// 	cout << arr[i] << " " ;

	delete[] arr;
	return 0;
}