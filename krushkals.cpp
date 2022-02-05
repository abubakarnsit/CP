#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
    
        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}

class dsu
{
  int*parent;
  int*rank;
  int v;
  public:
  dsu(int v)
  {
      this->v=v;
      parent=new int[v];
      rank=new int[v];
      for(int i=0;i<v;i++)
      {
          parent[i]=-1;
          rank[i]=1;
      }
  }
  int find(int x)
  {
      if(parent[x]==-1)
      return x;
      return parent[x]=find(parent[x]);
  }
  void unite(int x,int y)
  {
      int a=find(x);
      int b=find(y);
      if(a!=b)
      {
          if(rank[a]<rank[b])
          {
              parent[a]=b;
              rank[b]+=rank[a];
          }
          else
          {
              parent[b]=a;
              rank[a]+=rank[b];
          }
      }
  }
};
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    int ans=0;
    vector<vector<int>>edges;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j]!=INT_MAX)
            {
                edges.push_back({graph[i][j],i,j});
            }
        }
    }
    sort(edges.begin(),edges.end()); 
    dsu v(V);
    for(auto edge:edges)
    {
        int x=edge[1];
        int y=edge[2];
        int w=edge[0];
        //cout<<x<<" "<<y<<" "<<w<<" "<<endl;
       if(v.find(x)!=v.find(y))
        {
            v.unite(x,y);
            ans=ans+w;
        }
    }
    cout<<endl;
    return ans;
}