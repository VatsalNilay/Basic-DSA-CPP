/*
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.   
Output Format :
The first and only line of output prints the sum of all nodes of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
190
*/

#include<iostream>
#include"tree.h"
using namespace std;

int sumOfNodes(TreeNode<int>*root)
{
    if(root -> children.size() == 0)
        return root -> data;
    
    int sum = 0;
    for (int i = 0; i < root -> children.size(); i++)
        sum += sumOfNodes(root -> children[i]);
    
    return sum + root -> data;
    
}
int main()
{
    TreeNode<int>* root = takeInput();
    cout << sumOfNodes(root);
    // print(root);
}