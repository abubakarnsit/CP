#include<bits/stdc++.h>
using namespace std;
int findset(int x,int*parent)
{
    if(parent[x]==x)
    return x;
    return parent[x]=findset(parent[x],parent);
}
void unite(int x,int y,int*parent)
{
    int a=findset(x,parent);
    int b=findset(y,parent);
    if(a!=b)
    {
        parent[a]=b;
    }

}
int main()
{
    int n;
    cin>>n;
    int parent[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    unordered_map<int,int>ma;
    for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            unite(x,y,parent);
        
        }
     for(int i=0;i<n;i++)
      findset(i,parent);
    cout<<"parents"<<endl;
     for(int i=0;i<n;i++)
      cout<<parent[i]<<" ";
    cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(ma.find(parent[i])==ma.end())
            {
                ma[parent[i]]=arr[i];
            }
            else
            {
                ma[parent[i]]+=arr[i];
            }       
        }
        int ans=0;
        for(auto it=ma.begin();it!=ma.end();it++)
        {
            cout<<it->first<<"->"<<it->second<<endl;
            ans=max(ans,it->second);
        }
        cout<<ans<<endl;
}