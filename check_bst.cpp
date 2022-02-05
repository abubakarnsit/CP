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
void levelordertraversal(node*root);
bool checkbst(node*);
int height(node*root)
{
    if(root==NULL)
    return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;

}
void replacebysum(node*root);
node * buildtree();
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
bool checkbst(node*root,int min,int max)
{
 if(root==NULL)
 return true;
 if(root->data<max&&root->data>min&&checkbst(root->left,min,root->data)&&checkbst(root->right,root->data,max))
 return true;
 return false;
}
void levelordertraversal(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        if(temp==NULL)
        {
         cout<<endl;
         q.pop();
         if(!q.empty())
         q.push(NULL);
        }
        else
        {
        cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
        q.pop();
        }
    }
}
void replacebysum(node*root)
{
    if(root==NULL)
    return ;
    if(root->right==NULL&&root->left==NULL)
    {
    root->data= root->data;
    return;
    }
    int temp=root->data;
    root->data=replacebysum(root->right)+replacebysum(root->left)+temp;
    return;

}
int main()
{
node* root=buildtree();

levelordertraversal(root);
cout<<endl;
replacebysum(root);
cout<<endl;
levelordertraversal(root);
if(checkbst(root,INT_MIN,INT_MAX))
cout<<" this is bst "<<endl;
else
cout<<" not bst "<<endl;
}