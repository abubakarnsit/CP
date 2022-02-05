#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n=10000000;
    int a;
    cin>>a;
    bitset<n>p;
    p.set()=1;
    p[0]=0;
    p[1]=0;
    for(ll int i=2;i*i<n;i++)
    {
        if(p[i]==1)
        {
            for(ll int j=i*i;j<n;j=j+i)
            p[j]=0;
        }
    }
    for(int i=2;i<a;i++)
    {
        if(p[i]==1)
        cout<<i<<" ";
    }

}