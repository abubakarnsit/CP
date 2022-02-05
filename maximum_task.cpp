#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}
void print(vector<pair<int,int>>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second;
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    vector<pair<int,int>>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    print(v);
    sort(v.begin(),v.end(),compare);
    print(v);
    int count=1;
    int end=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        int start=v[i].first;
        if(start>=end)
        {
            count++;
            end=v[i].second;
        }
    }
    cout<<count<<endl;
}

