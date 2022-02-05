#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll find(vector<ll>v,ll i,ll k);
int main()
{
    ll n;
    cin>>n;
    int arr[n];
    vector<ll>v;
    for(ll i=0;i<n;i++)
     arr[i]=1;
    for(ll i=2;i<=sqrt(n);i++)
    {
        ll j=i;
        while((i*j)<=n)
        {
            if(arr[i*j-1]==1)
               arr[i*j-1]=0;
            j++;
        }
    }
    ll count=0;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]==1)
        v.push_back(i+1);
    }
    for(ll i=0;i<v.size();i++)
    cout<<v[i]<<"  ";
    cout<<endl;
    int t;
    cin>>t;
    while(t--)
    {
    ll k;
    cin>>k;
    ll ans=0;
    int s=v.size();
    for(int i=1;i<(1<<s);i++)
    ans=ans+find(v,i,k);
    cout<<ans<<endl;
    }
}
ll find(vector<ll>v,ll i,ll k)
{
    int count=0;
    ll j=0;
    ll b=1;
    while(i>0)
      {
       if((i&1)==1)
       {
       b=b*v[j];
       count++;
       }
       i=i>>1;
       j++; 
      }
      ll ret=k/b;
      if(count%2==0)
      return (-ret);
      else
      return ret;
}