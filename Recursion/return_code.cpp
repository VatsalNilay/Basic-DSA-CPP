/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
Write a program to return the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/
/***************************************************************************************************/
#include<iostream>
#include<string>
using namespace std;

int ret_codes(string input, string out[])
{
	if (input.empty())
	{
		out[0] = "";        //base case is used for initialising the 'out' array
		return 1;
	}

	int first = input[0] - '0';
	char fchar = first + 'a' - 1;    //ok
	char schar = '\0';
	//there are 2 choices here, use 1st digit only, or to use it with 2nd digit as 2 digit number

	string o1[100], o2[100];                  //2 choices, so 2 arrays are there

	//case 1
	int e1 = ret_codes(input.substr(1), o1);
	int e2 = 0; 	/*altho for 1st case e2 is not necessary, we are using it here for declaration purposes.
				but it should be 0...bcoz lets assume case 2 is not there...so the for loop will be troublesome.*/

	//case 2...input size should be greater than or equal to 2...i mean u had have 2 numbers na
	if (input.size() > 1)
	{
		int second = 10 * first + input[1] - '0';
		if (second > 9 && second < 27)
		{
			schar = second + 'a' - 1;
			e2 = ret_codes(input.substr(2), o2);
		}
	}

	for (int i = 0; i < e1; ++i)
		out[i] = fchar + o1[i]; //

	for (int i = 0; i < e2; ++i)
		out[i + e1] = schar + o2[i];

	return e1 + e2;
}

int main()
{
	string s, out[100];
	cin >> s;
	int total_elements = ret_codes(s, out);

	for (int i = 0; i < total_elements; ++i)
		cout << out[i] << endl;
}