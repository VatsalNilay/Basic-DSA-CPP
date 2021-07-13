/*You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.*/

/**********************************************************************************************/

#include<iostream>
#include<string>
using namespace std;

void printKeypad(string input, string out)
{
	if (input.empty())
	{
		cout << out << endl;
		return;
	}

	string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

	int first = input[0] - '0';
	int i = 0;

	while (i < table[first].length())
	{
		printKeypad(input.substr(1), out + table[first][i++]);
	}
	return;

}

int main()
{
	string input;
	cin >> input;
	printKeypad(input, "");
}