/*
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/
/*************************************************************************************/

#include <iostream>
using namespace std;


void merge(int arr[], int si, int ei)
{
  int mid = (si + ei) / 2;
  int *temp = new int[ei - si]; //
//int temp[ei - si]...has to use this as declaring array dynamically gives error in the codezen
  int k = 0, i = si, j = mid + 1;

  while (i <= mid && j <= ei)
  {
    if (arr[i] > arr[j])
      temp[k++] = arr[j++];    //merging two sorted arrays in a temp array
    else
      temp[k++] = arr[i++];
  }

  while (i <= mid)
    temp[k++] = arr[i++];

  while (j <= ei)
    temp[k++] = arr[j++];

  int n = 0;
  for (int i = si; i <= ei; ++i)
    arr[i] = temp[n++];          //copying the contents of temp array back into the original array

  delete [] temp;
}

void mergeSort(int input[], int si, int ei)
{
  if (si >= ei)
    return;

  int mid = (si + ei) / 2;

  mergeSort(input, si, mid); //sort the first half
  mergeSort(input, mid + 1, ei); //sort the second half

  merge(input, si, ei); //merge the two halves

}

void mergeSort(int input[], int size) {
  mergeSort(input, 0, size - 1);
}


int main()
{
  int length;
  cin >> length;
  int* input = new int[length];
  for (int i = 0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for (int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
  delete []input;
}