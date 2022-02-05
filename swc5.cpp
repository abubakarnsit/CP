#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    vector<int>*l;
    public:
    graph(int v)
    {
        this->v=v;
        l=new vector<int> [v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(int src)
    {
        queue<int>q;
        q.push(src);
        int visited[v]={0};
        visited[src]=1;
        while(!q.empty())
        {
            int temp=q.front();
            cout<<temp<<" ";
            q.pop();
            for(auto it:l[temp])
            {
             if(visited[it]==0)
             {
                 q.push(it);
                 visited[it]=1;
             }
            }
        }
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(auto it:l[i])
            {
                cout<<it<<",";
            }
            cout<<endl;
        }
    }
};
int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(2,1);
    g.addedge(2,3);
    g.addedge(0,4);
    g.addedge(4,5);
    g.addedge(3,5);
    g.print();
    g.bfs(0);

}