#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node*buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();
    return root;
}
void printlevelorder(node*root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(q.size()!=0)
            q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
    }


}
int height(node*root)
{
    if(root==NULL)
    return 0;
    return(1+max(height(root->left),height(root->right)));
}

int diameter(node*root)
{
    if(root==NULL)
    return 0;
    int d1=height(root->left);
    int d2=height(root->right);
    return max(d1+d2,max(diameter(root->left),diameter(root->right)));
}

pair<int,int> optimiseddiameter(node*root)
{
    pair<int,int>p;
    if(root==NULL)
    {
    p.first=0;
    p.second=0;
    return p;
    }
    pair<int,int>pl=optimiseddiameter(root->left);
    pair<int,int>pr=optimiseddiameter(root->right);
    p.first=max(pl.first,pr.first)+1;
    int d1=pl.first+pr.first;
    int d2=pl.second;
    int d3=pr.second;
    p.second=max(d1,max(d2,d3));
    return p;
}

int replacebysum(node*root)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL and root->right==NULL)
    return root->data;
    int a=root->data;
    root->data=replacebysum(root->left)+replacebysum(root->right);
    return a+root->data;

}
bool balancedtree(node*root)
{
    if(root==NULL)
    return true;
    int h1=height(root->left);
    int h2=height(root->right);
    return (abs(h1-h2)<2 and balancedtree(root->left) and balancedtree(root->right));
}
pair<int,bool>optimisedheight(node*root)
{
  pair<int,bool>p;
  if(root==NULL)
  {
      p.first=0;
      p.second=true;
      return p;
  }  
  pair<int,bool>pl=optimisedheight(root->left);
  pair<int,bool>pr=optimisedheight(root->right);
  p.first=max(pl.first,pr.first)+1;
  bool b=false;
  if(abs(pl.first-pr.first)<2)
  b=true;
  p.second=(b and pr.second and pl.second);
  return p; 
}
node* levelorderbuildtree()
{
    int d;
    cin>>d;
    queue<node*>q;
    node*root=new node(d);
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            temp->left=new node(c1);
            q.push(temp->left);
        }
        if(c2!=-1)
        {
            temp->right=new node(c2);
            q.push(temp->right);
        }
    }
    
    return root;
}
pair<int,int>maxpairsubset(node*root)
{
    pair<int,int>p;
    if(root==NULL)
    {
        p.first=0;
        p.second=0;;
        return p;
    }
    pair<int,int>pl=maxpairsubset(root->left);
    pair<int,int>pr=maxpairsubset(root->right);
    p.first=root->data+pl.second+pr.second;
    p.second=max(pl.first,pl.second)+max(pr.first,pr.second);
    
    return p;

}
void traverse(node*root,int d,map<int,vector<int>>&m)
{
    if(root==NULL)
    {
        return;
    }
    m[d].push_back(root->data)
    traverse(root->left,d-1,m);
    traverse(root->right,d+1,m);
}
void traversevertical(node*root)
{
    int d=0;
    map<int,vector<int>>m;
    traverse(root,d,m);
    for(auto p:m)
    {
        int key=p.first;
        vector<int>v=p.second;
        for(auto a:v)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printlevelk(node*root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
    cout<<root->data<<" ";
    printlevelk(root->left,k-1);
    printlevelk(root->right,k-1);
}

void helperprint(node*root,int &maxlev,int lev)
{
    if(root==NULL)
    return;
    if(maxlev<lev)
    {
        cout<<root->data<<endl;
        maxlev=lev;
    }
    helperprint(root->left,maxlev,lev+1);
    helperprint(root->right,maxl,lev+1);
}
void printleftview(node*root)
{
    int maxle=0;
    int lev=1;
    helperprint(root,maxl,lev);
}



void printrightview(node*root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=1;i<=n;i++)
        {
            node*temp=q.front();
            q.pop();
            if(i==n)
            cout<<temp->data<<endl;
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
    }
}


int main()
{
    node*root=buildtree();
    printlevelorder(root);
    cout<<endl<<height(root)<<endl;
    cout<<endl<<diameter(root)<<endl;
    //int ans=replacebysum(root);
    printlevelorder(root);
    cout<<endl<<balancedtree(root)<<endl<<endl;
    pair<int,bool>p=optimisedheight(root);
    cout<<p.first<<" "<<p.second<<endl<<endl;
    pair<int,int>p2=maxpairsubset(root);
    cout<<p2.first<<" "<<p2.second<<endl<<endl;
    printlevelk(root,3);

}