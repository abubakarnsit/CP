#include<bits/stdc++.h>
using namespace std;
class graph
{
vector<int>*g;
int v;
public:
graph(int v)
{
    this->v=v;
    g=new vector<int>[v];
}
void addedge(int x,int y)
{
    g[x].push_back(y);
    g[y].push_back(x);

}
void print(int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i<<"->";
        for(auto nbr:g[i])
        {
            cout<<nbr<<",";
        }
        cout<<endl;
    }
}
void singlesourceshortespath(int v,int src)
{
    int dist[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto nbr:g[temp])
        {
            if(dist[nbr]==INT_MAX)
            {
                dist[nbr]=dist[temp]+1;
                q.push(nbr);
            }
        }
    }
    cout<<"distance from "<<src;
    for(int i=0;i<v;i++)
    {
        cout<<"from "<<src;
        cout<<" to "<<i<<" is "<<dist[i]<<endl;
    }
}
};
int main()
{
    graph  g(7);
    g.addedge(0,1);
    g.addedge(0,5);
    g.addedge(0,6);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(5,3);
    g.print(7);
    g.singlesourceshortespath(7,0);
}