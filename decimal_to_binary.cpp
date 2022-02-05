#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int p=1;
    int ans=0;
    while(n>0)
    {
        ans+=(n&1)*p;
        p=p*10;
        n=n>>1;
    }
    cout<<ans;
}
