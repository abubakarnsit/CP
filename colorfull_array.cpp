#include<bits/stdc++.h>
using namespace std;
class dsu
{
int *par;
public:
    dsu(int v)
    {
        par=new int [v];
        for(int i=0;i<v;i++)
        par[i]=i;
    }
    int get(int x)
    {
        if(par[x]==x)
        return x;
        return (par[x]=get(par[x]));
    }
    void unite(int x,int y)
    {
         x=get(x);
         y=get(y);
        if(x!=y)
        {
            par[x]=max(par[x],par[y]);
            par[y]=max(par[y],par[x]);
        }
    }
};

int main()
{
int n;
cin>>n;
dsu s(n+2);
int k;
cin>>k;
int l[k];
int r[k];
int c[k];
for(int i=0;i<k;i++)
{
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;z;
    l[i]=x;
    r[i]=y;
    c[i]=z;
}
int ans[n]={0};
for(int i=k-1;i>=0;i--)
{
    int ri=s.get(l[i]);
    while(ri<=r[i])
    {
        ans[ri]=c[i];
        s.unite(ri,ri+1);
        ri=s.get(ri);
    }
}
for(int i=0;i<n;i++)
cout<<ans[i]<<endl;
}