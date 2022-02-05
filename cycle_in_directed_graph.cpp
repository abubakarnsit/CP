#include <bits/stdc++.h>
using namespace std;
bool dfs_helper(bool*visited,bool*stack,int src,vector<int>adj[])
{
    visited[src]=true;
    stack[src]=true;
    for(auto nbr:adj[src])
    {
        if(!visited[nbr])
        {
            bool next=dfs_helper(visited,stack,nbr,adj);
            if(next)
            return true;
        }
        else if(stack[nbr]==true)
        return true;
    }
    stack[src]=false;
    return  false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool stack[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    bool ans=false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            bool a=dfs_helper(visited,stack,i,adj);
            ans=a|ans;
        }
    }
    return ans;
}
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
} 