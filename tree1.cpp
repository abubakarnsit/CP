#include<bits/stdc++.h>
using namespace std;

class node
{
public:
int data;
node *left;
node *right;

 node(int d)
 {
     data=d;
     left=NULL;
     right=NULL;
 }

};
void postorder(node* root);
void inorder(node* root);
void preorder(node* root);
int height(node*root);
void bfs(node *root);
node * buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node * root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void inorder(node*root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);

}
void preorder(node*root)
{
    if(root==NULL)
    return ;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void printkthlevel(node*root,int k)
{
    if(root==NULL)
    return ;
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
}
int height(node *root)
{
    if(root==NULL)
    return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void bfs(node *root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        cout<<temp->data<<" ";
         q.pop();
        if(temp->left)
        {
        q.push(temp->left);
        }
        if(temp->right)
        {
        q.push(temp->right);
        }
    }
    return;
}
int main()
{
node * root=buildtree();
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
int a=height(root);
cout<<a<<endl;
printkthlevel(root,3);
cout<<endl;
for(int i=1;i<=a;i++)
{
    printkthlevel(root,i);
    cout<<endl;
}
bfs(root);

}