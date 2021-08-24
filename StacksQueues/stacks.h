#include"ll_class.h"
using namespace std;
class Stack
{
    Node *head;
    Node *tail;
    int size;
    
    public:
        Stack()
        {
            head = tail = NULL;
            size = 0;
        }
	/*----------------- Public Functions of Stack -----------------*/
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    int push(int data)
    {
        Node *temp = new Node(data);
        if(!head)
        {
            head = temp;
            tail = temp;
            tail -> next = NULL;
        }
        else
        {
            temp -> next = head;
            head = temp;
        }
        size += 1; //dont keep forgeting about the size
    }
    
    int pop()
    {
        if(isEmpty())
            return -1;
        Node *temp = head;
        head = head -> next;
        int ans = temp -> data;
        delete []temp;
        size -= 1; //missed it
        return ans;
    }
    int top()
    {
        if(!head)
            return -1;
        return head -> data;
    }

};