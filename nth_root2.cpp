#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int
float ans(ll n ,int k,int p);
int main()
{
    ll n;
    cout<<"enter the number"<<endl;
    cin>>n;
    cout<<"enter the kth root"<<endl;
    int k;
    cin>>k;
    cout<<"endl the number of decimal points (must be less than 8) "<<endl;
    int p;
    cin>>p;
    cout<<ans(n,k,p)<<endl;
    
}
float ans(ll n ,int k,int p)
{
    ll s=0;
    ll e=n;
    float ans=0;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(pow(mid,k)==n)
        return mid;
        if(pow(mid,k)<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }       
    }
    float a=0.1;
    for(int i=1;i<=p;i++)
    {
        while(pow(ans,k)<=n)
        {
            ans=ans+a;
        }
        ans=ans-a;
        a=a/10;
    }
    return ans;
}