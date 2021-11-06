#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode
{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;

    if(rootData == -1)
        return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);

    while(!pn.empty())
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        int lchild, rchild; 
        cin >> lchild;
        if(lchild != -1)
        {
            BinaryTreeNode<int> *l_child = new BinaryTreeNode<int>(lchild);
            front -> left = l_child;
            pn.push(l_child);
        }
        cin >> rchild;
        if(rchild != -1)
        {
            BinaryTreeNode<int> *r_child = new BinaryTreeNode<int>(rchild);
            front -> right = r_child;
            pn.push(r_child);
        }
    }
    return root;
}

void print(BinaryTreeNode<int> *root)
{
    if(root -> data == -1)
        return;

    queue<BinaryTreeNode<int>*> pq;
    pq.push(root);

    while(!pq.empty())   
    {
        BinaryTreeNode<int>* front = pq.front();
        pq.pop();
        cout << front -> data << ":";
        if(front -> left)
        {
            cout << "L:" << front -> left -> data << ",";
            pq.push(front -> left);
        }
        else
            cout << "L:-1" <<",";
        
        if(front -> right)
        {
            cout << "R:" << front -> right -> data << endl;
            pq.push(front -> right);
        }
        else
            cout << "R:-1" << endl;
    }
}