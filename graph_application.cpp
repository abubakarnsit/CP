#include<bits/stdc++.h>
using namespace std;
class graph
{
    int v;
    vector<int>*g;
    public:
    graph(int v)
    {
        this->v=v;
        g=new vector<int>[v];
    }
    void addedge(int a,int b)
    {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int dfs(int src,bool* visited,int*arr)
    {
        int ans=arr[src];
        visited[src]=true;
        for(auto nbr:g[src])
        {
            if(visited[nbr]==false)
            {
                ans+=dfs(nbr,visited,arr);
            }
        }
        return ans;
    }
    void print(int v)
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(auto hg:g[i])
            {
                cout<<hg<<",";
            }
            cout<<endl;
        }
    }

};
int main()
{
    int n;
    cin>>n;
    graph h(n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        h.addedge(x,y);
    }
    h.print(n);
    int fg=0;
    bool visited[n];
    for(int i=0;i<n;i++)
    visited[i]=false;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            int s=h.dfs(i,visited,arr);
            fg=max(fg,s);
            cout<<s<<" ";
        }
    }
    cout<<endl<<fg;
}