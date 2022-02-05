#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>>v;
#define ll long long int
int main()
{
 ll n;
 cin>>n;
 for(int i=2;i*i<=n;i++)
 {
     if(n%i==0)
     {
     int count=0;
     while(n%i==0)
     {
         count++;
         n=n/i;
     }
     v.push_back(make_pair(i,count));
     }
 }
 if(n!=1)
 {
     v.push_back(make_pair(n,1));
 }
 for(auto it=v.begin();it!=v.end();it++)
 {
     cout<<it->first<<" "<<it->second<<endl;
 }
}
