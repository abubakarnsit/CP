#include<iostream>
using namespace std;
int ans(long long int);
int main()
{
    long long int n;
    cin>>n;
    cout<<ans(n)<<endl;
}
int ans(long long int n)
{
    long long int p=5;
    int ans=0;
    while((n/p)>0)
    {
        ans+=n/p;
        p=p*5;
    }
   return ans;
}