/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/

#include<iostream>
#include<climits>
#include"tree.h"
using namespace std;

class nodePair
{
    public:
        TreeNode<int> * node;
        int sum;
};


nodePair* maxSumHelper(TreeNode<int>* root)
{
    if(!root)
    {
        nodePair* ans = new nodePair();
        ans -> node = NULL;
        ans -> sum = INT_MIN;
        return ans;
    }

    int sum = root -> data;
    for (int i = 0; i < root -> children.size(); i++)
        sum += root -> children[i] -> data;
    
    nodePair* rootAns = new nodePair();
    rootAns -> node = root;
    rootAns -> sum = sum;

    for (int i = 0; i < root -> children.size(); i++)
    {
        // nodePair* rec = new nodePair();
        nodePair* rec = maxSumHelper(root -> children[i]);

        if(rec -> sum > rootAns -> sum )
            rootAns = rec;
            
    }
    return rootAns;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root)
{
    return maxSumHelper(root) -> node;
}
int main()
{
    TreeNode<int>* root = takeInput();
    TreeNode<int>* ans = maxSumNode(root);

    if(ans)
        cout << ans -> data << endl;

}