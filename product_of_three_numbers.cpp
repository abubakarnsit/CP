#include<iostream>
#include<vector>
using namespace std;

#define ll long long int
vector<pair<int,int>>v;
int main()
{
    ll n;
    cin>>n;
    string str="NO";
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
    v.push_back(make_pair(n,1));
    if(v.size()>=3)
    str="YES";
    if(v.size()==1&&v[0].second>=6)
    str="YES";
    if(v.size()==2&&(v[0].second>=3||v[1].second>=3))
    str="YES";
    cout<<str<<endl;
}