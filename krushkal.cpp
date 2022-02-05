#include<iostream>
#include<vector>
#include<algorithm>
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

    int getsuperparent(int x)
    {
        if(x==parent[x])
        return x;
        return parent[x]=getsuperparent(parent[x]);
    }

    void unite(int a,int b)
    {
        int par1=getsuperparent(a);
        int par2=getsuperparent(b);
        if(par1!=par2)
        {
            parent[par1]=par2;
        }      
    }
};

int main()
{
    int node,edge;
    cin>>node>>edge;
    graph g;
    int ans=0;
    g.init(node);
    vector<vector<int>> edges(edge);
    for(int i=0;i<edge;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        edges[i]={w,x,y};
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edge;i++)
    {
        int x=edges[i][1];
        int y=edges[i][2];
        int w=edges[i][0];
        if(g.getsuperparent(x)!=g.getsuperparent(y))
        {
            g.unite(x,y);
            cout<<x<<" "<<y<<" "<<w<<endl;
            ans+=w;
        }
    }
    cout<<ans<<endl;
}