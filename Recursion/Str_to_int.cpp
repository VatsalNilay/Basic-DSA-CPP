/*
String to Integer

Write a recursive function to convert a given string into the number it represents.
That is input will be a numeric string that contains only numbers, you need to convert
the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231
Sample Output 1 :
1231

Sample Input 2 :
12567
Sample Output 2 :
12567
*/
/*********************************************************************************************************************************/
#include<cstring> //for strlen()
#include <iostream>
using namespace std;

int stringToInput(char arr[], int n)
{
	if (n == 0)
		return 0;

	int last = arr[n - 1] - '0';
	int rec = stringToInput(arr, n - 1);

	return rec * 10 + last;
}

int stringToInput(char arr[])
{
	int n = strlen(arr);
	return stringToInput(arr, n);
}

int main()
{
	char input[50];
	cin >> input;
	cout << stringToInput(input) + 1 << endl; //1 is added to show that we have an integer

	return 0;
}