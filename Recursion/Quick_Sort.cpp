/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7
*/

/********************************************************************************/

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int si, int ei)
{
	int ci = si;
	for (int i = si + 1; i <= ei; ++i)
	{
		if (arr[si] > arr[i])
			ci++;
	}
	swap(arr[si], arr[ci]);

	int i = si, j = ci + 1;

	while (i < ci && j <= ei)
	{
		// if (arr[i] > arr[ci] && arr[j] <= arr[ci])
		// {
		// 	swap(arr[i], arr[j]);
		// 	i++; j++;
		// }
		// else if (arr[i] > arr[ci])
		// 	j++;
		// else                          //this gives wrong ans for some cases
		// 	i++;

		if (arr[i] < arr[ci])
			i++;
		else if (arr[j] >= arr[ci])
			j++;
		else
		{
			swap(arr[i], arr[j]);
			i++; j++;
		}
	}
	return ci;
}

void quickSort(int arr[], int si, int ei)
{
	if (si >= ei)
		return;

	int p = partition(arr, si, ei);

	quickSort(arr, si, p - 1);
	quickSort(arr, p + 1, ei);
}

void quickSort(int arr[], int n)
{
	quickSort(arr, 0, n - 1);
}

int main() {
	int n;
	cin >> n;

	int *input = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	quickSort(input, n);
	for (int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}

	delete [] input;

}
