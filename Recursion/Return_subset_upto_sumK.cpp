/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Constraints :
1 <= n <= 20

Sample Input :
9
5 12 3 17 1 18 15 3 17
6
Sample Output :
3 3
5 1
*/
/**************************************************************************************************/
#include<iostream>
using namespace std;

int ret_subset_sum_k(int arr[], int size, int ans[][50], int key)
{
	if (size == 0)
	{
		if (key == 0)
		{
			ans[0][0] = 0;
			return 1;
		}
		else
			return 0;
	}
//so each element has 2 choices...whether it contributes in the ans array or not.
	int o1[1000][50], o2[1000][50];

	int r1 = ret_subset_sum_k(arr + 1, size - 1, o1, key);       //not contributing
	int r2 = ret_subset_sum_k(arr + 1, size - 1, o2, key - arr[0]); //contributing

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j <= o1[i][0]; j++) //since first element is not included...we paste the array as it is
			ans[i][j] = o1[i][j];
	}

	for (int i = 0; i < r2; i++)
	{
		ans[i + r1][0] = 1 + o2[i][0];
		ans[i + r1][1] = arr[0];

		for (int j = 1; j <= ans[i + r1][0]; j++)
			ans[i + r1][j + 1] = o2[i][j];  //because 'j' in ans[x][j] is filled upto 1...
	}
	return r1 + r2;

}

int main()
{
	int n, k, ans[1000][50];
	cin >> n >> k;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int row = ret_subset_sum_k(arr, n, ans, k);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 1; j <= ans[i][0]; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	delete [] arr;
}