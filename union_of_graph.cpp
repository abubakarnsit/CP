#include<iostream>
#include<list>
#include<vector>
using namespace std;
class graph
{
    vector<int>parent;
  public:
  void init(int n)
  {
      parent.resize(n);
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
      }
  }
  int getparent(int x)
  {
      if (x==parent[x])
      return x;
      return(parent[x]=getparent(parent[x]));
  }
  void unite(int a,int b)
  {
     int par1=getparent(a);
      int par2=getparent(b);
      if(par1!=par2)
      {
          parent[par1]=par2;
      }
  }
};
int main()
{
    graph g;
    int n,m;
    cin>>n>>m;
    g.init(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(g.getparent(x)!=g.getparent(y))
        {
            g.unite(x,y);
        }
        else
        {
            cout<<"cycle detected"<<endl;
        }
        
    }
}