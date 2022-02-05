#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void print(int arr[],ll n);
int main()
{
    ll n;
    cin>>n;
    int arr[n];
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
    for(ll i=0;i<n;i++)
    {
        if(arr[i]==1)
        
       {
           cout<<i+1<<" ";
          count++;
       }
        }    
    cout<<endl;
    cout<<"total prime numbers is "<<count<<endl;
}
void print(int arr[],ll n)
{
    for(ll i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}