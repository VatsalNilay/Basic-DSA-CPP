#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input)
{
    if(input.empty())
        return;
    
    int temp = input.front();
    input.pop();
    reverseQueue(input);
    input.push(temp);
}

int main()
{
    int size;
    cin >> size;
    queue<int> q1;

    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        q1.push(val);
    }
    reverseQueue(q1);
    while(!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    
}