#include<bits/stdc++.h>
using namespace std;
class graph
{
 unordered_map<string,vector<pair<string,int>>>l;
 public:
 void addedge(string x,string y,bool bi,int wt)
 {
   l[x].push_back(make_pair(y,wt));
   if(bi)
   {
       l[y].push_back(make_pair(x,wt));
   }
 }
 void show()
 {
     unordered_map<string,vector<pair<string,int>>>::iterator ptr;
     for(ptr=l.begin();ptr!=l.end();ptr++)
     {
         cout<<ptr->first<<"->";
         for(auto it=ptr->second.begin();it!=ptr->second.end();it++)
         {
             cout<<it->first<<" "<<it->second<<", ";
         }
         cout<<endl;
     }
 }
};
int main()
{
 graph g;
 g.addedge("A","B",true,20);
 g.addedge("D","C",true,40);
 g.addedge("D","B",true,30);
 g.addedge("A","C",true,10);
 g.addedge("A","D",false,50);
 g.show();
}