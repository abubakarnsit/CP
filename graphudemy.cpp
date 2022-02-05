#include<bits/stdc++.h>
using namespace std;
class graph{
    list<int>*l;
    int v;
    public:
    graph(int v){
        this->v=v;
        l=new list<int>[v];
    }
    void addegde(int i,int j,bool undir=true)
    {
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for( auto node:l[i])
            cout<<node<<",";
            cout<<endl;
        }
    }
    void bfs(int src)
    {
        bool *vis=new bool[v]{0};
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto node:l[temp])
            {
                if(!vis[node])
                {
                    q.push(node);
                    vis[node]=true;
                }
            }
        }
        cout<<endl;
    }

    void distance(int src)
    {
        bool *vis=new bool[v]{0};
        queue<int>q;
        int dist[v]={0};
        dist[src]=0;
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto node:l[temp])
            {
                if(!vis[node])
                {
                    dist[node]=dist[temp]+1;
                    q.push(node);
                    vis[node]=true;
                }
            }
        }
        for(int i=0;i<v;i++)
        cout<<dist[i]<<" ";
        cout<<endl;

    }

};
int main()
{
    graph g(7);
    g.addegde(0,1,true);
    g.addegde(1,2,true);
    g.addegde(3,5,true);
    g.addegde(5,6,true);
    g.addegde(4,5,true);
    g.addegde(0,4,true);
    g.addegde(3,4,true);
    g.addegde(2,3,true);
    g.print();
    g.bfs(1);
    g.distance(0);
}