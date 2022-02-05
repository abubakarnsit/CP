#include<iostream>
#include<set>
#include<list>
#include<queue>
#include<map>
#include<climits>
#include<unordered_map>
using namespace std;
template<typename T>
class graph
{
    unordered_map<T,list<pair<T,int>>>m;
    public:
    void addedge(T a,T b,int c)
    {
        m[a].push_back(make_pair(b,c));
        m[b].push_back(make_pair(a,c));
    }
    void print()
    {
        for(auto it=m.begin();it!=m.end();it++)
        {
            cout<<it->first<<"->";
            for(auto it2=m[it->first].begin();it2!=m[it->first].end();it2++)
            {
                cout<<"("<<it2->first<<","<<it2->second<<")";
            }
            cout<<endl;
        }
    }
    void dijkstra(T src)
    {
        unordered_map<T,int>dist;
        set<pair<int,T>>s;
        for(auto it=m.begin();it!=m.end();it++)
        {
            dist[it->first]=INT_MAX;
        }
        dist[src]=0;
            for(auto it4=dist.begin();it4!=dist.end();it4++)
            cout<<it4->first<<" "<<it4->second<<endl;
            cout<<endl;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            pair<int,T>p=*(s.begin());
            T name=p.second;
            cout<<name<<endl;
            for(auto it2=m[name].begin();it2!=m[name].end();it2++)
            {
                if(dist[name]+it2->second<dist[it2->first])
                {
                    auto f=s.find(make_pair(dist[it2->first],it2->first));
                    if(f!=s.end())
                    s.erase(f);
                    s.insert(make_pair(dist[name]+it2->second,it2->first));
                    dist[it2->first]=dist[name]+it2->second;
                }

            }
            s.erase(s.begin());
            for(auto it4=dist.begin();it4!=dist.end();it4++)
            cout<<it4->first<<" "<<it4->second<<endl;
            cout<<endl;
        }
        for(auto it4=dist.begin();it4!=dist.end();it4++)
        cout<<it4->first<<" "<<it4->second<<endl;
    }
};
int main()
{
  graph <string>india;
  india.addedge("amritser","delhi",1);
  india.addedge("amritser","jaipur",4);
  india.addedge("jaipur","delhi",2);
  india.addedge("jaipur","mumbai",8);
  india.addedge("bhopal","agra",2);
  india.addedge("mumbai","bhopal",3);
  india.addedge("agra","delhi",1);
  //india.addedge("delhi","delhi",0);
  india.print();
  cout<<endl;
  india.dijkstra("amritser");
}