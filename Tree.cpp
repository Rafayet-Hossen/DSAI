#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
node *buildtree(node *root)
{
    cout << "Enter data:\n";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return nullptr;

    cout << "Enter data for left :\n";
    root->left = buildtree(root->left);
    cout << "Enter data for right:\n";
    root->right = buildtree(root->right);
    return root;
}
void levelorderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp == nullptr)
        {
            cout << "\n";
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root:\n";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << "\n";
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp->data << "\n";
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = nullptr;
    // root = buildtree(root);
    // cout<<"The tree is:\n";
    // levelorderTraversal(root);
    // cout<<"\nInorder traversal\n";
    // inorder(root);
    // cout<<"\nPreorder traversal\n";
    // preorder(root);
    // cout<<"\nPostOrder traversal\n";
    // postorder(root);
    buildFromLevelOrder(root);
    cout<<"\nPreorder traversal\n";
    preorder(root);

    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1