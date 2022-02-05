#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    unordered_set<int>s;
    for(int i=0;i<v.size();i++)
    s.insert(v[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int count=0;
        if(s.find(v[i]-1)!=s.end())
        {
            continue;
        }
        else
        {
            
           while(s.find(v[i])!=s.end())
           {
               count++;
               
               v[i]++;
           } 
        }  
        ans=max(ans,count);     
    }
    cout<<ans<<endl;
}