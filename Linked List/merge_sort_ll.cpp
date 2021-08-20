/* Given a singly linked list of integers, sort it using 'Merge Sort.'
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90*/

#include<iostream>
using namespace std;
#include"ll_class.h"

Node *merge(Node *head1, Node *head2)
{
    if(!head1)
        return head2;
    if(!head2)
        return head1;
    
    Node *newhead = NULL, *newtail= NULL;
    
    if(head1 -> data > head2 -> data)
    {
        newhead = newtail = head2;
        head2 = head2 -> next;
    }
    else
    {
        newhead = newtail = head1;
        head1 = head1 -> next;
    }

    while(head1 && head2)
    {
        if(head1 -> data > head2 -> data)
        {
            newtail -> next = head2;
            newtail = head2;
            head2 = head2 -> next;
        }
        else
        {
            newtail -> next = head1;
            newtail = head1;
            head1 = head1 -> next;
        }
    }

    if(head1)
        newtail -> next = head1;
    if(head2)
        newtail -> next = head2;
    return newhead;
}

// Node *middle(Node*head)
// {
//     if(!head)
//         return head;
//     Node *slow = head, *fast = head;
//     while (fast -> next && fast -> next -> next)
//     {
//         fast = fast -> next -> next;
            // slow = slow -> next;
//     }
    
//     return slow;
// }

Node* merge_sort(Node *head)
{
    if(!head || !head -> next)
        return head;

    Node *mid1  = mid(head); 
    Node *half1 = head;
    Node *half2 = mid1 -> next;
    mid1 -> next = NULL;

    half1 = merge_sort(half1);
    half2 = merge_sort(half2);

    Node *newhead = merge(half1,half2);
    return newhead;

}

int main()
{
    cout << "Enter ll: ";
    Node *head = takeInput();

    Node *head1 = merge_sort(head);
    print(head1);
}