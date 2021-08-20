#include<iostream>

using namespace std;
#include"ll_class.h"

int main()
{
    Node *head = takeInput();
    head = reverse(head);
    print(head);
}