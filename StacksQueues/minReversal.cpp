/*
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int countReversal(string s1)
{
    if(s1.length()&1)
        return -1;
    stack<int> s;
    int count = 0;
    char c1,c2;
    int i = 0;

    while(s1[i] != '\0')
    {
        if(s1[i] == '{')
            s.push(s1[i]);
        else
        {
            if(s.empty())
                s.push(s1[i]);
            else
            {
                if(s.top() == '}')
                    s.push(s1[i]);
                else
                    s.pop();
            }
        }
        i++;
    }
    while (!s.empty())
    {
        c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();

        if(c1 != c2)
            count += 2;
        else
            count += 1;
    }
    
    return count;
}

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << countReversal(s) << endl; 
}