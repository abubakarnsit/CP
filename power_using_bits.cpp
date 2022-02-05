#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=1;
    while(b>0)
    {
        if(b&1==1)
        {
            ans=ans*a;
        }
        b=b>>1;
        a=a*a;
    }
    cout<<ans<<endl;
    
}