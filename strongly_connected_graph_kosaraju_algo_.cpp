 #include<bits/stdc++.h>
 using namespace std;

void dfs2(int src,bool *visited,vector<int>*rev_graph)
 {
     
     visited[src]=true;
     cout<<src<<" ";
     for(auto nbr:rev_graph[src])
     {
         if(!visited[nbr])
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
         if(!visited[nbr])
         {
             dfs(nbr,visited,graph,stac);
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
     for(int i=0;i<stac.size();i++)
     cout<<stac[i]<<" ";
     cout<<endl<<endl;
     
     for(int i=0;i<v;i++)
     visited[i]=false;
     for(int i=0;i<v;i++)
     {
         cout<<i<<"->";
         for(auto nbr:rev_graph[i])
         cout<<nbr<<" ";
         cout<<endl;
     }
     cout<<endl<<endl;
     cout<<"strongly connected graphs are "<<endl;
     char a='A';
     for(int i=stac.size()-1;i>=0;i--)
     {
         if(!visited[stac[i]])
         {
             cout<<a<<"-->";
             dfs2(stac[i],visited,rev_graph);
             cout<<endl;
             a++;
         }
     }

 }
