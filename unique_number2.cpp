#include<bits/stdc++.h>
using namespace std;
int findset(int n);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
     int ans=0;
     for(int i=0;i<n;i++)
     ans=ans^arr[i];
     cout<<ans<<endl;
     int a=findset(ans);
     cout<<a<<endl;
     int c=0;
     for(int i=0;i<n;i++)
     {
         if((arr[i]&(1<<a-1))>0)
             c=c^arr[i];
     }
     cout<<min(c,ans^c)<<" "<<max(c,ans^c)<<endl;
}
int findset(int n)
{
    int i=1;
    while((n&1)==0)
    {
     i++;
     n=n>>1;
    }
    return i;
}