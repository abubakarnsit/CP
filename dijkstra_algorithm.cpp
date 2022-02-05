#include<bits/stdc++.h>
using namespace std;
class graph
{   
    unordered_map<int,vector<pair<int,int>>>m;
    public:
    void addedge(int x,int y,int w)
    {
      m[x].push_back(make_pair(y,w));
    }
    void print()
    {
        for(auto df:m)
        {
            cout<<df.first<<"->";
            for(auto nbr:df.second)
            {
                cout<<"("<<nbr.first<<","<<nbr.second<<")";
            }
            cout<<endl;
        }
    }
    void dikstra(int src)
    {
        unordered_map<int,int>dist;
        for(auto nbr:m)
        {
            dist[nbr.first]=INT_MAX;

        }
        for(auto br:dist)
        {
            cout<<br.first<<",,"<<br.second<<endl;
        }
        cout<<endl<<endl;
        set<pair<int,int>>s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            pair<int,int>p=*(s.begin());
            s.erase(s.begin());
            cout<<p.first<<"->"<<p.second<<endl;;
            int dis=p.first;
            dist[p.second]=dis;
            for(auto nbr:m[p.second])
            {
                //nbr.first=node
                //nbr.second=weight
                if(dist.find(nbr.first)==dist.end())
                {
                    dist[nbr.first]=INT_MAX;
                }
                if(dist[nbr.first]>dis+nbr.second)
                {
                    auto f=s.find(make_pair(dist[nbr.first],nbr.first));
                    if(f!=s.end())
                    s.erase(f);
                    dist[nbr.first]=dis+nbr.second;
                    s.insert(make_pair(dis+nbr.second,nbr.first));
                }

            }
        for(auto br:dist)
        {
            cout<<br.first<<",,"<<br.second<<endl;
        }
        cout<<endl<<endl;

        }
        for(auto nbr:dist)
        {
            cout<<nbr.first<<"->"<<nbr.second<<endl;
        }

    }

};
int main()
{
    graph g;
    g.addedge(0,1,2);
    g.addedge(1,2,3);
    g.addedge(2,3,3);
    g.addedge(0,3,10);
    g.addedge(0,2,6);
    g.print();
    g.dikstra(0);
}