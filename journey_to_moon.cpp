#include<bits/stdc++.h>
using namespace std;
class graph
{
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
 void print(int v)
 {
     for(int i=0;i<v;i++)
     {
         cout<<i<<"->(";
         for(auto nbr:gr[i])
         {
             cout<<nbr<<",";
         }
         cout<<")"<<endl;;
     }
 }
 int sizeofg(int v,int src,bool*visited)
 {
     int size=0;
     visited[src]=true;
     queue<int>q;
     q.push(src);
     while(!q.empty())
     {
         int temp=q.front();
         q.pop();
         size++;
         for(auto nbr:gr[temp])
         {
             if(!visited[nbr])
             {
                 visited[nbr]=true;
                 q.push(nbr);
             }
         }
     }
     return size;
 }
 int sizeusingdfs(int v,int src,bool*vis)
 {
     int size=1;
     vis[src]=true;
     for(auto nbr:gr[src])
     {
         if(!vis[nbr])
         {
             size=size+sizeusingdfs(v,nbr,vis);
         }
     }
     return size;
 }
};
int main()
{
graph g(5);
g.addedge(0,1);
g.addedge(2,3);
g.addedge(0,4);
g.print(5);
bool visited[5];
memset(visited,false,sizeof(visited));
for(int i=0;i<5;i++)
{
    if(!visited[i])
    cout<<g.sizeofg(5,i,visited)<<endl;
}
for(int i=0;i<5;i++)
visited[i]=false;
for(int i=0;i<5;i++)
{
    if(!visited[i])
    cout<<g.sizeusingdfs(5,i,visited)<<endl;
}
}