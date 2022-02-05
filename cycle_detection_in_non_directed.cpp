#include<bits/stdc++.h>
using namespace std;
bool dfs_helper(int node,vector<int>g[],bool *visited,int parent)
{
    visited[node]=true;
    for(auto nbr:g[node])
    {
        if(!visited[nbr])
        {
            bool next=dfs_helper(nbr,g,visited,node);
            if(next)
            return true;
        }
        else if(nbr!=parent)
        return true;
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   bool visited[V];
   for(int i=0;i<V;i++)
   {
       visited[i]=false;
   }
   bool ans=false;
   for(int i=0;i<V;i++)
   {
       if(!visited[i])
       {
       bool a=dfs_helper(i,g,visited,-1);
       ans=ans|a;
       }
   }
   return ans;
   
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}