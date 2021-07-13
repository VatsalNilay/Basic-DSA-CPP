/*
Given an integer n, using phone keypad find out and print all the possible strings that can
be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n
Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
/*******************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string out)
{
	if (num == 0 || num == 1)
	{
		cout << out << endl;
		return;
	}

	int self = num % 10;
	if (self == 0)
	{
		cout << " " << endl;
		return ;
	}
	else if (self == 1)
	{
		cout << " " << endl;
		return;
	}
	else if (self == 2)
	{
		printKeypad(num / 10, 'a' + out);
		printKeypad(num / 10, 'b' + out);
		printKeypad(num / 10, 'c' + out);
	}
	else if (self == 3)
	{
		printKeypad(num / 10, 'd' + out);
		printKeypad(num / 10, 'e' + out);
		printKeypad(num / 10, 'f' + out);
	}
	else if (self == 4)
	{
		printKeypad(num / 10, 'g' + out);
		printKeypad(num / 10, 'h' + out);
		printKeypad(num / 10, 'i' + out);
	}
	else if (self == 5)
	{
		printKeypad(num / 10, 'j' + out);
		printKeypad(num / 10, 'k' + out);
		printKeypad(num / 10, 'l' + out);
	}
	else if (self == 6)
	{
		printKeypad(num / 10, 'm' + out);
		printKeypad(num / 10, 'n' + out );
		printKeypad(num / 10, 'o' + out);
	}
	else if (self == 7)
	{
		printKeypad(num / 10, 'p' + out);
		printKeypad(num / 10, 'q' + out);
		printKeypad(num / 10, 'r' + out);
		printKeypad(num / 10, 's' + out);
	}
	else if (self == 8)
	{
		printKeypad(num / 10, 't' + out);
		printKeypad(num / 10, 'u' + out);
		printKeypad(num / 10, 'v' + out);
	}
	else if (self == 9)
	{
		printKeypad(num / 10, 'w' + out);
		printKeypad(num / 10, 'x' + out);
		printKeypad(num / 10, 'y' + out);
		printKeypad(num / 10, 'z' + out);
	}

}

void printKeypad(int num)
{
	printKeypad(num, "");
}

int main() {
	int num;
	cin >> num;

	printKeypad(num);

	return 0;
}