/*
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/
#include<iostream>
#include"BTree.h"
using namespace std;

    BinaryTreeNode<int>* buildTree(int* pre, int prelength, int *in, int inlength)
    {
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[0]);
        if(prelength == 0)
            return NULL;
        
        int r = 0;
        while(in[r] != pre[0])
            r++;

        int l_size = r;
        int r_size = inlength - 1 - r;

        BinaryTreeNode<int> *lchild = buildTree(pre + 1, l_size, in, l_size);
        BinaryTreeNode<int> *rchild = buildTree(pre + 1 + l_size, r_size, in + 1 + l_size, r_size);

        root -> left = lchild;
        root -> right = rchild;

        return root;
    }
int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    print(root);
}