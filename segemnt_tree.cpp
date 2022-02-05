#include<iostream>
#include<climits>
using namespace std;


void buildtree(int *a,int *tree,int s,int e,int index)
{
    if(s==e)
    {
        tree[index]=a[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(a,tree,s,mid,2*index);
    buildtree(a,tree,mid+1,e,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}


void updatenode(int*tree,int ss,int se,int i, int increment,int index)
{
    if(i>se or i<ss)
    return;
    if(ss==se)
    {
        tree[index]=increment;
        return;
    }
    int mid=(se+ss)/2;
    updatenode(tree,ss,mid,i,increment,2*index);
    updatenode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

void updaterange(int *tree,int ss, int se,int i, int j,int increment,int index)
{
    if(i>se or j<ss)
    return ;
    if(ss==se)
    {
        tree[index]=increment;
        return;
    }
    int mid=(se+ss)/2;
    updaterange(tree,ss,mid,i,j,increment,2*index);
    updaterange(tree,mid+1,se,i,j,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}


int find(int *tree,int qs,int qe,int s,int e,int index)
{
    if(s>=qs and e<=qe)
    return tree[index];
    if(qe<s or qs>e)
    return INT_MAX;
    int mid=(s+e)/2;
    int left=find(tree,qs,qe,s,mid,2*index);
    int right=find(tree,qs,qe,mid+1,e,2*index+1);
    return min(left,right);
}


int main()
{
    int a[]={1,3,2,-5,6,4};
    int n=sizeof(a)/sizeof(int);
    int *tree=new int[4*n+1];
    for(int i=0;i<4*n+1;i++)
    {
        tree[i]=INT_MAX;
    }
    buildtree(a,tree,0,n-1,1);
    for(int i=1;i<4*n+1;i++)
    {
        cout<<tree[i]<<" ";
    } 
    cout<<endl;
    /*int t;
    cin>>t;
    while(t--)
    {
        int qs,qe;
        cin>>qs>>qe;
        cout<<find(tree,qs,qe,0,n-1,1)<<endl;;

    }*/
    updatenode(tree,0,n-1,2,10,0);
    for(int i=1;i<4*n+1;i++)
    {
        cout<<tree[i]<<" ";
    }

}
