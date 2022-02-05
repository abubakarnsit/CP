#include<bits/stdc++.h>
using namespace std;
class graph
{
  int V;
  list<int>*li;
public:
      graph(int v){
       V=v;
      li=new list<int>[v];
      }
      void addedge(int a,int b, bool di=true)
      {
      li[a].push_back(b);
      if(di)
      {
      li[b].push_back(a);
      }
      }
      void print()
      {
      for(int i=0;i<V;i++)
      {
        cout<<i<<"-->";
            for(int vertex:li[i])
            cout<<vertex<<",";
            cout<<endl;
          }
        }

};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.print();


}