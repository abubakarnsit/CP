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
    g.bfs(0);

}