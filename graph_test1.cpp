#include<bits/stdc++.h>
using namespace std;
class graph{
    vector<int>*gr;
    public:
    graph(int v)
    {
        gr=new vector<int>[v];

    }
    void addedge(int x,int y)
    {
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    void show(int v)
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(vector<int>::iterator ptr=gr[i].begin();ptr!=gr[i].end();ptr++)
            cout<<*ptr<<",";
            cout<<endl;
        }
    }
    void bfs(int v,int src)
    {
        bool visited[v];
        for(int i=0;i<v;i++)
        visited[i]=false;
        visited[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int temp=q.front();            
            q.pop();
            cout<<temp;
            for(auto nbr:gr[temp])
            {
                if(!visited[nbr])
                {
                visited[nbr]=true;
                q.push(nbr);
                }
            }
        }

    }
    void dfs(int v,int src)
    {
        bool visited[v];
        for(int i=0;i<v;i++)
        visited[i]=false;
        dfs_helper(visited,src);
    }
    void dfs_helper(bool *visited,int src)
    {
        visited[src]=true;
        for(auto nbr:gr[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(visited,nbr);
            }
        }
        cout<<src<<" ";
    }
    bool cyclemile(int node,bool*visited,int parent)
    {
        visited[node]=true;
        for(auto nbr:gr[node])
        {
            if(!visited[nbr])
            {
                bool cycle=cyclemile(nbr,visited,node);
                if(cycle)
                return true;
            }
            else if(nbr!=parent)
            return true;
        }
        return false; 
    }
    bool containscysle(int v)
    {
        bool visited[v];
        memset(visited,false,sizeof(visited));
        return cyclemile(0,visited,0);
    }
};
int main()
{
graph g(4);
g.addedge(0,1);
g.addedge(2,1);
g.addedge(0,2);
g.addedge(2,3);
g.show(4);
g.bfs(4,0);
cout<<endl;
g.dfs(4,0);
}