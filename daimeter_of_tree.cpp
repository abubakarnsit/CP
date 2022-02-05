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
pair<int,int>fastdiameter(node*root);
int height(node*root)
{
    if(root==NULL)
    return 0;
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;

}
node * buildtree();
int diameter(node*root);
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
int diameter(node *root)
{
    if(root==NULL)
    return 0;
    int l1=height(root->left);
    int l2=height(root->right);
    int op1=l1+l2;
    int op2=diameter(root->left);
    int op3=diameter(root->right);
    return max(max(op1,op2),op3);
}
pair<int,int>fastdiameter(node*root)
{
    pair<int,int>p1;
    if(root==NULL)
    {
        p1.first=p1.second=0;
        return p1;                   //first==height,second==diameter
    }
    //otherwise
    pair<int,int>p2=fastdiameter(root->left);
    pair<int,int>p3=fastdiameter(root->right);
    pair<int,int>res;
    res.first=p3.first+p2.first+1;
    res.second=max(p3.first+p2.first,max(p2.second,p3.second));
    return res;

}
int main()
{
node* root=buildtree();
cout<<diameter(root)<<endl;
pair<int,int> p=fastdiameter(root);
cout<<p.first<<" "<<p.second;
}