/*Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
Line 1 : Size of array
Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:[] (this just represents an empty array, don't worry about the square brackets)
12
20
20 12
15
15 12
15 20
15 20 12 */

/*********************************************************************************************/

//At j[][0], total size of the subset present in that row is placed
#include<iostream>
using namespace std;

int ret_subset(int arr[], int size, int ans[][20])
{
	if (size == 0)
	{
		ans[0][0] = 0; //means that if the size is zero or becomes 0, then the subset has 0 elements
		return 1;
	}

	int rec = ret_subset(arr + 1, size - 1, ans); //Subset for all the elements except the arr[0]
//rec wil store the number of rows or subset of n - 1 elements


//now for the rest subsets, we will just copy all the subsets and attach the first element...
	for (int i = 0; i < rec; i++)
	{
		ans[i + rec][0] = 1 + ans[i][0]; //since we are copying the same row and adding 1 element...the size will inc by 1
		ans[i + rec][1] = arr[0]; //attaching the first element(keep in mind that it is a subset...ordering matters)

		for (int j = 1; j <= ans[i + rec][0]; j++)
		{
			ans[i + rec][1 + j] = ans[i][j]; //copying the elements
		}
	}
	return 2 * rec; //now the subset has 2*rec rows
}

int main()
{
	int out[3500][20], n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ans = ret_subset(arr, n, out);

	for (int i = 0; i < ans; i++)
	{
		for (int j = 1; j <= out[i][0]; j++)
		{
			cout << out[i][j] << " " ;
		}
		cout << endl;
	}
	delete[] arr;
}