#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int arr[10]={0};
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        arr[str[i]-'0']++;
        count++;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    long long int fact[16];
    fact[0]=1;
    for(int i=1;i<16;i++)
    {
        fact[i]=fact[i-1]*i;

    }
   long long int ans=fact[count];
   for(int i=0;i<10;i++)
   {
       ans=ans/fact[arr[i]];
   }
   cout<<ans<<endl;
   if(arr[0]!=0)
   {
       long long int d=arr[0];
       arr[0]--;
       count--;
       d=fact[count];
       for(int i=0;i<10;i++)
       {
           d=d/fact[arr[i]];
       }
       cout<<endl<<d<<endl;
    ans=ans-d;
   }
   cout<<ans<<endl;
}