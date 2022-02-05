#include<bits/stdc++.h>
using namespace std;
int spanningtree(vector<pair<int,int>>*g,int v,int e)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    int ans=0;
    bool visited[v];
    for(int i=0;i<v;i++)
    visited[i]=false;
    while(!q.empty())
    {
        pair<int,int>p=q.top();
        int wei=p.first;
        int dest=p.second;
        q.pop();
        
        if(visited[dest])
        {
        continue;
        }
        visited[dest]=true;
        ans=ans+wei;
        for(auto it:g[dest])
        {
            if(visited[it.first]==0)
            {
                q.push({it.second,it.first});
            }
        }
    }
    return ans;
}
int main()
{
    int v;
    cin>>v;
    vector<pair<int,int>>gr[v];
    int e;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        gr[x].push_back(make_pair(y,w));
        gr[y].push_back(make_pair(x,w));
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<"-> ";
        for(auto it:gr[i])
        {
            cout<<"("<<it.first<<","<<it.second<<"),";
        }
        cout<<endl;
    }
    cout<<spanningtree(gr,v,e)<<endl;
}
