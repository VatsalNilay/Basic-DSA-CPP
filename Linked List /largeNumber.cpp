/*
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.
Input Constraints:
1 <= Length of Linked List <=10^6.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 

Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6

Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
*/
#include<iostream>
#include"ll_class.h"

using namespace std;

Node *nextLarge(Node *head)
{
    head = reverse(head);
    Node *temp = head;
    Node * extra = new Node(1);
    while(temp)
    {
        if(temp -> data == 9)
        {
            temp -> data = 0;
            if(temp -> next == NULL)
            {
                temp -> next = extra;
                break;
            }    
            temp = temp -> next;
        }
        else
        {
            temp -> data++;
            break;
        }
    }

    head = reverse(head);
    return head;

}
int main()
{
    Node *head = takeInput();
    head = nextLarge(head);
    print(head);
}