#include<iostream>
#include"ll_class.h"

Node *reverse1(Node *head)
{
    if(!head || !head -> next)
        return head;
    
    Node *rec = reverse1(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return rec;
}

bool palindrome(Node *head)
{
    if(!head || !head -> next)
        return head;
    
    Node *fast = head;
    Node *slow = head;

    while(fast -> next && fast -> next -> next)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    slow = reverse1(slow -> next);
    while(slow)
    {
        if(head -> data != slow -> data)
            return false;
        head = head -> next;
        slow = slow -> next;
    }
    return true;
}
using namespace std;
int main()
{
    Node *head = takeInput();
    // cout << palindrome(head)? cout << "Yes" : cout << "No" << endl;
    if(palindrome(head))
        cout << "yes" << endl;
    else
        cout << "No" << endl;
}