#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph
{
   unordered_map<string,list<pair<string,int>>>l;
   public:
   void addedge(string a,string b,bool bidirectional,int weight)
   {
       l[a].push_back(make_pair(b,weight));
       if(bidirectional)
       {
           l[b].push_back(make_pair(a,weight));
       }
   }
   void show()
   {
       
       for(unordered_map<string,list<pair<string,int>>>::iterator it=l.begin();it!=l.end();++it)
       {
           cout<<it->first<<"->";
           for(auto it2=it->second.begin();it2!=it->second.end();it2++)
           {
               cout<<"("<<it2->first<<","<<it2->second<<")";
           }
           cout<<endl;
       }
   }
   
};

int main()
{
graph g;
g.addedge("A","B",true,20);
g.addedge("A","C",true,50);
g.addedge("A","D",true,10);
g.addedge("B","C",true,30);
g.addedge("C","D",false,40);
g.show();
}
