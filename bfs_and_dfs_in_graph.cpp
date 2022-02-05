#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class graph
{
  map<T,list<T>>m;
  public:
  void addedge(T x,T y)
  {
      m[x].push_back(y);
      m[y].push_back(x);
  }
  void addedge2(T x,T y)
  {
      m[x].push_back(y);
  }
  void show()
  {
      for(auto it=m.begin();it!=m.end();it++)
      {
          cout<<it->first<<"->";
          for(auto it2=it->second.begin();it2!=it->second.end();it2++)
          {
              cout<<*it2<<",";
          }
          cout<<endl;
      }
  }
  void bfs(T src)
  {
      map<T,bool>visited;
      queue<T>q;
      q.push(src);
      visited[src]=true;
      while(!q.empty())
      {
          T temp=q.front();
          cout<<temp<<" ";
          for(auto it=m[temp].begin();it!=m[temp].end();it++)
          {
              if(!visited[*it])
              {
              q.push(*it);
              visited[*it]=true;
              }

          }
          q.pop();

      }
  }

  void dfs(T src)
  {
      map<T,bool>visited;
      for(auto it=m.begin();it!=m.end();it++)
      {
          visited[it->first]=false;
      }
      visited[src]=true;
      dfs_helper(src,visited);
  }
  
  void dfs_helper(T src,map<T,bool>&visited)
  {
      cout<<src<<" ";
      for(auto it=m[src].begin();it!=m[src].end();it++)
      {
          if(!visited[*it])
          {
              visited[*it]=true;
              dfs_helper(*it,visited);
          }
      }
      return;
  }


  void distancefromsource(T src)
  {
      map<T,int>dist;
      queue<T>q;
      for(auto it=m.begin();it!=m.end();it++)
      {
          dist[it->first]=INT_MAX;
      }
      q.push(src);
      dist[src]=0;
      while(!q.empty())
      {
          T temp=q.front();
          q.pop();
          for(auto it2=m[temp].begin();it2!=m[temp].end();it2++)
          {
              if(dist[*it2]==INT_MAX)
              {
                  q.push(*it2);
                  dist[*it2]=dist[temp]+1;
              }
          }
          
      }
      cout<<endl;
      for(auto it3=dist.begin();it3!=dist.end();it3++)
      {
          cout<<"the distance of "<<it3->first<<" from the "<<src<<" is "<<it3->second<<endl;
      }
  }

  void connectedgraph()
  {
      map<T,bool>visited;
      for(auto it=m.begin();it!=m.end();it++)
      {
          visited[it->first]=false;
      }
      int count=0;
      for(auto it=m.begin();it!=m.end();it++)
      {
          if(!visited[it->first])
          {
              visited[it->first]=true;
              cout<<"the "<<count<<" tree is ";
              dfs_helper(it->first,visited);
              cout<<endl;
              count++;
              
          }
      }
  }
  void topologicalsort()
    {
        map<T,bool>visited;
        list<T>l;
        for (auto it=m.begin();it!=m.end();it++)
        {
            visited[it->first]=false;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(!visited[it->first])
            {
            visited[it->first]=true;
            helper_topological(it->first,visited,l);
            }
        }
        for(auto it=l.begin();it!=l.end();it++)
        {
            cout<<*it<<" ";
        }
    }
    void helper_topological(T node,map<int,bool>&visited,list<T>&l)
    {
        for(auto it=m[node].begin();it!=m[node].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                helper_topological(*it,visited,l);          
            }   
        }
        l.push_front(node);
        return;
    }
};


int main()
{
    graph <int>g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(0,3);
    g.addedge(3,4);
    g.addedge(4,5);
    g.addedge(6,7);
    g.addedge(7,8);
    g.addedge(8,9);
    g.addedge(9,6);
    g.addedge(10,13);
    g.addedge(10,11);
    g.addedge(11,12);
    g.addedge(12,13);
    cout<<"adjacency list is"<<endl;
    g.show();
    cout<<endl<<"BFS is ";
    g.bfs(0);
    cout<<endl;
    g.distancefromsource(0);
    cout<<endl<<"DFS is";
    g.dfs(0);
    cout<<endl;
    g.connectedgraph();

    graph <int>g2;
    g2.addedge2(1,2);
    g2.addedge2(1,3);
    g2.addedge2(2,4);
    g2.addedge2(3,4);
    g2.addedge2(4,5);
    g2.topologicalsort();



}
