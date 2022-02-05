#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int count;
void dfs(vector<bool>&vis,int vert,int str,int graph[][MAX],int n,int v)
{
    vis[vert]=true;
    if(n==0)
    {
        vis[vert]=false;
        if(graph[vert][str]==1)
        {
            count++;
            return;
        }

    }
    for(int i=0;i<v;i++)
    {
        if(!vis[i] and graph[vert][i]==1)
        {
            dfs(vis,i,str,graph,n-1,v);
        }
        vis[vert]=false;
    }
    return count/2;
}
int main()
{
    int v;
    cin>>v;
    int graph[v][v];
    for(int i=0;i<v;i++)
     for(int j=0;j<v;j++)
      graph[i][j]=0;
    int edges;
    for(int i=0;i<edges;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    int cycle;
    cin>>cycle;
    count=0;
    vector<bool>vis(v,false);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        dfs(vis,i,i,graph,cycle-1,v);
    }

}