/*
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
For Example:
Alt txt

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.

Output Format:
The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.
Constraints:
1 <= N <= 10^3
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 

Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10
Note: Here, 1 is at the top of the stack.

Sample Input 2:
5
2 8 15 1 10
Sample Output 2:
2 8 15 1 10
*/

#include<iostream>
#include<stack>
using namespace std;
// we need 3 stacks in order to reverse them, for 3rd stack we will make the of use implicit stack i.e. recursion
void reverseStack(stack<int> &input, stack<int> &helper)
{
    if(input.empty())
        return;
    
    int self = input.top();
    input.pop();
    reverseStack(input,helper);

    while (!input.empty())
    {
        int val = input.top();
        input.pop();
        helper.push(val);
    }
    helper.push(self);
    while (!helper.empty())
    {
        int val = helper.top();
        helper.pop();
        input.push(val);
    } 
}
int main()
{
    stack<int> s1,s2;
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        s1.push(val);
    }

    reverseStack(s1,s2);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    
    
}