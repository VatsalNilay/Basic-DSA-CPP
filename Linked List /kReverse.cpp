#include<iostream>

using namespace std;
#include"ll_class.h"

Node *kreverse(Node *head, int k)
{
    if(k == 0 || k == 1)
    {
        cout <<" Head " << head -> data << " ";
        return head;
    }
    Node *current = head;
    Node *prev = NULL, *fwd = NULL;
    int count = 0;

    //Reverse first K nodes...
    while(count < k && current)
    {
        fwd = current -> next;
        current -> next = prev;
        prev = current;
        current = fwd;
        count++;
    }
    if(fwd)
    {
        // cout << head  -> data << " "; //not required
        head -> next = kreverse(fwd,k); // 1 2 3 4 5 -1 (2)...firstly 2 1 3 4 5 -1...so (2,1 is done by us)and since 1 was head...head -> next
                                        //should be done by recursion
    }
    cout << "Prev " <<prev -> data << "  ";
    return prev;
}

int main()
{
    Node*head = takeInput();
    int k;
    cin >> k;
    head = kreverse(head,k);
    cout  << endl;
    print(head);
}