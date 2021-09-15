/*
Given a generic tree, find and return the height of given tree.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the height of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3
*/
#include<iostream>
#include<climits>
#include"tree.h"
using namespace std;

int findHeight(TreeNode<int>* root)
{
    if(root -> children.size() == 0)
        return 1;

    int ans = INT_MIN;
    for (int i = 0; i < root -> children.size(); i++)
    {
        int height = 1 + findHeight(root -> children[i]);
        ans = max(ans,height);
    }
    return ans;
}

int main()
{
    TreeNode<int>* root = takeInput();
    cout << findHeight(root) << endl;
}