#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#define ll long long int
const ll M=1000000007;
map<ll ,ll>m;
ll ans(ll );
int main()
{
    ll n;
    cin>>n;
    m[0]=1;
    m[1]=1;
    if(n==0)
    cout<<0<<endl;
    else
    {
        cout<<ans(n)<<endl;
    }

}
ll ans(ll n)
{
    if(m.count(n))
    return m[n];
    ll k=n/2;
    i
    f(n%2==0)
    {
        return m[n]=(ans(k)*ans(k)+ans(k-1)*ans(k-1))%M;
    }
    else
    {
        return m[n]=(ans(k)*ans(k+1)+ans(k-1)*ans(k))%M;
    }
    
}