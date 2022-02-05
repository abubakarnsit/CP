#include<bits/stdc++.h>
using namespace std;
void bfs(int src,vector<int>*graph,int &ans,int v)
{
  int dist[v];
  for(int i=0;i<v;i++)
  dist[i]=INT_MAX;
  dist[src]=0;
  queue<int>q;
  q.push(src);
  while(!q.empty())
  {
      int node=q.front();
      q.pop();
      for(auto nbr:graph[node])
      {
          if(dist[nbr]==INT_MAX)
          {
              dist[nbr]=dist[node]+1;
              q.push(nbr);
          }
          else if(dist[nbr]>=dist[node])
          {
              ans=min(ans,dist[nbr]+dist[node]+1);
          }
      }
  }

}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>graph[v];
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans=INT_MAX;
    for(int i=0;i<v;i++)
    {
       bfs(i,graph,ans,v); 
    }
    if(ans==INT_MAX)
    cout<<"no cycle found "<<endl;
    else
    {
        cout<<"min cycle is of length "<<ans<<endl;
    } 
}