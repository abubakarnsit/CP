#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct graph
{
      list<T>*li;
      graph(T v){
      li=new list<T>[v];
      }
      void addedge(T a,T b, bool di=true)
      {
      li[a].push_back(b);
      if(di)
      {
      li[b].push_back(a);
      }
      }
      void print(T v)
      {
      for(T i=0;i<v;i++)
      {
        cout<<i<<"-->";
            for(auto it=li[i].begin();it!=li[i].end();it++)
            cout<<*it<<",";
            cout<<endl;
          }
        }
     void bfs(T src)
     {
        queue<T>q;
        unordered_map<T,bool>travel;
        q.push(src);
        travel[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            cout<<node<<"->";
            q.pop();
            for(auto it1=li[node].begin();it1!=li[node].end();it1++)
            {
                if(!travel[*it1])
                {
                    q.push(*it1);
                    travel[*it1]=true;
                }
            }
        }
     }
     void sps(T src, T v)
     {
         queue<T>q;
         q.push(src);
         map<T,int>dist;
         for(int i=0;i<v;i++)
          dist[i]=INT_MAX;
          dist[src]=0;
         map<T,T>parent;
         parent[src]=src;
         while(!q.empty())
         {
             T node=q.front();
             q.pop();
             for(auto it1=li[node].begin();it1!=li[node].end();it1++)
             {
                 if(dist[*it1]==INT_MAX)
                 {
                     q.push(*it1);
                     dist[*it1]=dist[node]+1;
                     parent[*it1]=node;
                 }
             }
         }
        for(int i=0;i<v;i++)
         {
             cout<<"dist of node from "<<src<<" to node "<< i<<" is "<<dist[i]<<endl;
         }


     }
    void dfs(T src)
    {
        unordered_map<T,int>trav;
        trav[src]=true;
        find(src,trav[src],trav);
    }
    void find(int src,bool visited,unordered_map<T,int>trav)
    {
        cout<<src<<"-->";
        for(auto it4=li[src].begin();it4!=li[src].end();it4++)
        {
            if(!trav[*it4])
            {
            src=*it4;
            trav[*it4]=true;
            find(src,trav[src],trav);
            }
        }
    }
};
int main()
{
    graph<int> g(6);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,4);
    g.addedge(3,5);
    g.addedge(2,3);
    g.addedge(3,4);
    g.print(6);
    cout<<endl;
    cout<<"breadth for search will give "<<endl;
    g.bfs(0);
    cout<<endl;
    cout<<" depth for search will give "<<endl;
    g.dfs(0);
    cout<<endl;
    g.sps(0,6);

}