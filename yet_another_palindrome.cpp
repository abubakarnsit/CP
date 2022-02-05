#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string ans="NO";
    unordered_map<int,vector<int>>m;
    for(int i=0;i<n;i++)
    {
      m[arr[i]].push_back(i);
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second.size()>=3)
        ans="YES";
    }
    for (auto it1=m.begin();it1!=m.end();it1++)
    {
        if(it1->second.size()==2&&it1->second[0]!=it1->second[1]-1)
        ans="YES";
    }
    cout<<ans;
}