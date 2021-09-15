#include<iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector<TreeNode<T>*>children;

        TreeNode(T data)
        {
            this -> data = data;
        }

        ~TreeNode()
        {
            for (int i = 0; i < children.size(); i++)
            {
                delete children[i];
            }
            
        }
};

TreeNode<int>* takeInput()
{
    int rootdata;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    // queue <int> pn;
    queue<TreeNode<int>*> pn;
    pn.push(root);

    while(!pn.empty())
    {
        TreeNode<int>* front = pn.front();
        pn.pop();
        int childNum;
        cin >> childNum;

        for(int i = 0; i < childNum; i++)
        {
            int data;
            cin >> data;
            TreeNode<int>* newNode = new TreeNode<int>(data);
            front -> children.push_back(newNode);
            pn.push(newNode);
        }
    }
    return root;
}

void print(TreeNode<int>* root)
{
    if(root == NULL)
        return;

    queue<TreeNode<int>*> pn;
    pn.push(root);

    while(!pn.empty())
    {
        TreeNode<int>* front = pn.front();
        pn.pop();

        cout << front -> data << ":";
        for (int i = 0; i < front -> children.size(); i++)
        {
            if(i != front -> children.size() - 1)
                cout << front -> children[i] -> data << ",";
            else
                cout << front -> children[i] -> data ;
            
            pn.push(front -> children[i]);
        }
        cout << endl;
    }
}

