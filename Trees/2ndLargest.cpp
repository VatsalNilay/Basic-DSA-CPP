/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/

#include<iostream>
#include<climits>
#include"tree.h"

class makePair
{
    public:
        TreeNode<int>* max;
        TreeNode<int>* smax;

    makePair(TreeNode<int>* max, TreeNode<int>* smax)
    {
        this -> max = max;
        this -> smax = smax;
    }
};


makePair* helper(TreeNode<int>* root)
{
    if(!root)
    {
        // makePair* ans = new makePair();
        // ans -> max = ans -> smax = NULL;
        // return ans;
        return new makePair(NULL, NULL);
    }
    makePair* ans = new makePair(root, NULL);

    for(int i = 0; i < root -> children.size(); i++)
    {
        makePair* childAns = helper(root -> children[i]);

        if(childAns -> max -> data > ans -> max -> data)
        {
            if(childAns -> smax == NULL)
            {
                ans -> smax = ans -> max;
                ans -> max = childAns -> max;
            }
            else
            {
                if(childAns -> smax -> data > ans -> max -> data)
                {
                    ans -> smax = childAns -> smax;
                    ans -> max = childAns -> max;
                }
                else
                {
                    ans -> smax = ans -> max;
                    ans -> max = childAns -> max;
                }
            }
        }
        else
        {
            // if((ans -> smax == NULL || childAns -> max -> data > ans -> smax -> data) && (ans -> max -> data != childAns -> max -> data))
            if(ans -> max -> data != childAns -> max -> data)
            {
                if(ans -> smax == NULL || childAns -> max -> data > ans -> smax -> data)
                    ans -> smax = childAns -> max;
            }
        }    
    }
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root)
{
    return helper(root) -> smax;
}
using namespace std;
int main()
{
    TreeNode<int>* root = takeInput();
    TreeNode<int>* ans = getSecondLargestNode(root);

    if(ans)
        cout << ans -> data << endl;
    else
        cout << INT_MIN << endl;

}