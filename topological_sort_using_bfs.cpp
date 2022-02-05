#include<iostream>
#include<list>
#include<queue>
#include<map>
using namespace std;
class graph
{
    list<int>*l;
    int v;
    public:
    graph(int V)
    {
    v=V;
    l=new list<int>[v];
    }
    void addedge(int x,int y)
    {
        l[x].push_back(y);
    }
    void topological()
    {
        queue<int>q;
        int arr[v]={0};
        for (int i=0;i<v;i++)
        {
            for(auto it=l[i].begin();it!=l[i].end();it++)
            {
              arr[*it]++;
            }
        }
        for(int i=0;i<v;i++)
        {
            if(arr[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            {
                for(auto it=l[temp].begin();it!=l[temp].end();it++)
                {
                    arr[*it]--;
                    if(arr[*it]==0)
                    q.push(*it);
                }
            }
            cout<<temp<<" ";
        }
    }

    bool checkcycle()
    {
        bool visited[v];
        int parent[v];
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
            parent[i]=i;
        }
        int src=0;
        visited[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto it=l[temp].begin();it!=l[temp].end();it++)
            {
                if(visited[*it]==true and parent[temp]!=*it)
                return true;
                else if(!visited[*it])
                {
                    q.push(*it);
                    visited[*it]=true;
                    parent[*it]=temp;
                }
            
            }
        }
        return false;
        
    }

};
int main()
{
    graph g(6);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(2,5);
    g.addedge(1,4);
    g.addedge(3,5);
    g.addedge(4,5);
    g.topological();
    cout<<endl;
    graph g2(4);
    g2.addedge(0,1);
    g2.addedge(0,2);
    g2.addedge(2,1);
    if(g2.checkcycle())
    {
        cout<<"yes it contains cycle "<<endl;
    }
    else
    {
        cout<<"it does not contain cycle"<<endl;
    }
    
}