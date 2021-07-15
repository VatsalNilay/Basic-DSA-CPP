/*
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba
*/
/*******************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int ret_permutaions(string input, string out[])
{
	if (input.empty())
	{
		out[0] = "";
		return 1;
	}
	string temp[100];
	int small = ret_permutaions(input.substr(1), temp);

	int k = 0;
	for (int i = 0; i < small; ++i)
	{
		for (int j = 0; j < input.size() ; j++)
			out[k++] = temp[i].substr(0, j) + input[0] + temp[i].substr(j, input.size());
	}

	return k;
}

int main()
{
	string input;
	cin >> input;
	string ans[100];

	int size = ret_permutaions(input, ans);

	for (int i = 0; i < size; ++i)
		cout << ans[i] << endl;
}