#include<bits/stdc++.h>
using namespace std;
class graph
{
    list<int>*li;
public:
    graph(int n)
    {
    li=new list<int>[n];
    }
   void  addedge(int a,int b)
    {
        li[a].push_back(b);
    }
    void minpath(int src,int n)
    {
        queue<int>q;
        q.push(src);
        map<int,int>dist;
        for(int i=0;i<n;i++)
            dist[i]=INT_MAX;
        map<int,int>parent;
        dist[src]=0;
        parent[src]=src;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it=li[node].begin();it!=li[node].end();it++)
            {
                if(dist[*it]==INT_MAX)
                {
                    q.push(*it);
                    dist[*it]=dist[node]+1;
                    parent[*it]=node;

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX)
             cout<<"min dist from "<<src+1<<" to "<<i+1<<" is ---> "<<"CAN'T REACH HERE"<<endl;
            else
            cout<<"min dist from "<<src+1<<" to "<<i+1<<" is ---> "<<dist[i]<<endl;
        }
        cout<<endl;
        cout<<endl;
        cout<<"min number of steps to win the game is "<<dist[n-1];
        cout<<endl;
        int a=99;

        while(a!=0)
        {
            cout<<parent[a]<<"<--";
            a=parent[a];
        }
    }
};
int main()
{
    int n;
    cin>>n;
   // n=100;
    int arr[n+1]{0};
    graph g(n);
    arr[11]=-7;
    arr[29]=-12;
    arr[21]=-14;
    arr[16]=-12;
    /*arr[56]=12;
    arr[70]=10;
    arr[88]=-30;
    arr[93]=-16;
    arr[27]=12;*/
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=6;j++)
        g.addedge(i,i+j+arr[i+j+1]);
    }
    g.minpath(0,n);
}