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
node * buildtree();
void levelordertraversal(node*root);
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

void levelordertraversal(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
        while(!q.empty())
        {
            node*f=q.front();
            if(f==NULL)
            {
                cout<<endl;
                q.pop();
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
             cout<<f->data<<" ";
             if(f->left) 
             q.push(f->left);
             if(f->right)
             q.push(f->right);
             q.pop();
            }
        }
}
int main()
{
    node *root=buildtree();
    levelordertraversal(root);

}