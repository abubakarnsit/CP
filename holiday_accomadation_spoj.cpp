#include<iostream>
#include<list>
using namespace std;
class graph
{
  int v;
  list<pair<int,int>>*l;
  public:
  graph(int V)
  {
      l=new list<pair<int,int>>[V];
      v=V;
  }
  void addedge(int x,int y,int w)
  {
      l[x].push_back(make_pair(y,w));
      l[y].push_back(make_pair(x,w));
  }
  int dfs(int src)
  {
      bool visited[v];
      int count[v];
      for(int i=0;i<v;i++)
      {
          visited[i]=false;
          count[i]=0;
      }
      int ans=0;
      dfs_helper(src,visited,count,ans);
      return ans;

  }
  int dfs_helper(int src,bool*visited,int *count,int&ans)
  {
      visited[src]=true;
      count[src]=1;
      for(auto it=l[src].begin();it!=l[src].end();it++)
      {
          int node=it->first;
          int weight=it->second;
          if(!visited[node])
          {
              count[src]+=dfs_helper(node,visited,count,ans);
              int nx=count[node];
              int ny=v-nx;
              ans+=min(nx,ny)*weight*2;
          }
      }
      return count[src];
  }
};
int main()
{
    graph g(4);
    g.addedge(0,1,3);
    g.addedge(1,2,2);
    g.addedge(2,3,2);
    cout<<g.dfs(0)<<endl;

}