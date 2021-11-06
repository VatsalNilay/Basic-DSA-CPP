#include<iostream>
using namespace std;
#include"ll_class.h"

Node *EvenAfterOdd(Node *head)
{
    if(!head || !head -> next)
        return head;
    Node *oddh = NULL, *evenh = NULL;
    Node *oddt = NULL, *event = NULL;
    while (head)
    {
        if(head -> data & 1)
        {
            if(!oddh)
                oddh = oddt = head;
            else
            {
                oddt -> next = head;
                oddt = head;
            }
        }
        else
        {
            if(!evenh)
                evenh = event = head;
            else
            {
                event -> next = head;
                event = head;
            }
        }
        head = head -> next;
    }
    
    if(!evenh)
    {
        return oddh;
    }
    else if(!oddh)
    {
        return evenh;
    }
    else
    {
        oddt -> next = evenh;
        return oddh;
    }
}
int main()
{
    Node *head = takeInput();
    head = EvenAfterOdd(head);
    print(head);
}