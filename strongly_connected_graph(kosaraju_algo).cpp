 #include<bits/stdc++.h>
 using namespace std;

void dfs2(int src,bool *visited,vector<int>rev_graph)
 {
     cout<<src<<" ";
     visited[src]=true;
     for(auto nbr:rev_graph[src])
     {
         if(!visited[*nbr])
         {
             dfs2(nbr,visited,rev_graph);
         }
     }
 }

void dfs(int src,bool *visited,vector<int>*graph,vector<int>&stac)
 {
     visited[src]=true;
     for(auto nbr:graph[src])
     {
         if(!visited[*nbr])
         {
             dfs(*nbr,visited,graph,stac);
         }
     }
     stac.push_back(src);
 }

 
 int main()
 {
     int v;
     cin>>v;
     vector<int>graph[v];
     vector<int>rev_graph[v];
     int e;
     cin>>e;
     int x,y;
     while(e--)
     {
         cin>>x>>y;
         graph[x].push_back(y);
         rev_graph[y].push_back(x);
     }
     bool visited[v]={0};
     vector<int>stac;
     for(int i=0;i<v;i++)
     {
         if(!visited[i])
         {
             dfs(i,visited,graph,stac);
         }
     }
     cout<<"strongly connected graphs are "<<endl;
     char a="A-->";
     memset(visited,0,sizeof(visited));
     for(int i=stac.size()-1;i>=0;i--)
     {
         if(!visited[stac])
         {
             dfs2(i,visited,rev_graph);
         }
     }

 }
