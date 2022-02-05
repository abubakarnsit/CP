#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>::iterator it4; 
class compare
{
    public:
    bool operator()(pair<string,int>p1,pair<string,int>p2)
    {
        return p1.second<p2.second;
    }
};
int main()
{
    pair<string,int>p1=make_pair("B",100);
    pair<string,int>p2=make_pair("A",170);
    pair<string,int>p3=make_pair("D",10);
    pair<string,int>p4=make_pair("C",48);
    multiset<pair<string ,int>>m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    for(auto it:m)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    multiset<pair<string,int>,compare>m2(m.begin(),m.end());
    for(auto it2:m2)
    {
         cout<<it2.first<<" "<<it2.second<<endl;
    }
    multiset<int>m3{1,2,3,3,3,3,3,4,4,5,5,5,6,6};
    for(int it:m3)
    {
        cout<<it<<" ";
    }
    pair<it4,it4>p4=m.equal_range(3);
    for(auto it54=p4.first;it54!=p4.second;it54++)
    {
        cout<<*it54<<" ";
    }
    
}