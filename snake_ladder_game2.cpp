#include<iostream>
#include<climits>
#include<list>
#include<map>
#include<queue>
using namespace std;
template<typename T>
class graph
{
  map<T,list<T>>m;
  public:
  void addedge(int x,int y)
  {
      m[x].push_back(y);
  }
  int find(T src,T dest)
  {
      map<T,int>dist;
      queue<T>q;
      q.push(src);
      for(auto it=m.begin();it!=m.end();it++)
      {
          dist[it->first]=INT_MAX;
      }
      dist[src]=0;
      while(!q.empty())
      {
          T temp=q.front();
          {
              for(auto it2=m[temp].begin();it2!=m[temp].end();it2++)
              {
                  if(dist[*it2]==INT_MAX)
                  {
                      dist[*it2]=dist[temp]+1;
                      q.push(*it2);
                  }
              }
          }
          q.pop();
      }
      for(auto it=dist.begin();it!=dist.end();it++)
      {
          if(dist[it->first]!=INT_MAX)
          cout<<"min steps required from "<<src<<" to "<<it->first<<" is "<<dist[it->first]<<endl;
          else
          {
              cout<<"it is not reachable from "<<src<<" to "<<it->first<<endl;
          }
          
          
      }
      return dist[dest];
  }

};
int main()
{
    graph<int>g;
    int jumps[37]={0};
    jumps[2]=13;
    jumps[5]=2;
    jumps[9]=18;
    jumps[17]=-13;
    jumps[18]=11;
    jumps[20]=-14;
    jumps[24]=-8;
    jumps[25]=10;
    jumps[32]=-2;
    jumps[34]=-22;
    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j=j+jumps[j];
            if(j<=36)
            g.addedge(i,j);
        }
    }
    g.addedge(36,36);
    int dist=g.find(0,36);
    cout<<endl;
    cout<<"min steps required to win the game is "<<dist<<endl;
}