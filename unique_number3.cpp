#include<bits/stdc++.h>
using namespace std;
void sum(int arr1[],int n);
int main()
{
    int n;
    cout<<"count of numbers in 3N+1 form"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int arr1[64]={0};
    for(int i=0;i<n;i++)
    sum(arr1,arr[i]);
    int ans=0;
    for(int i=0;i<64;i++)
        ans=ans+(pow(2,i)*(arr1[i]%3));
   cout<<"unique number is "<<ans<<endl;
}
void sum(int arr1[],int n)
{
    int i=0;
    while(n>0)
    {
        if(n&1==1)
        arr1[i]++;
        i++;
        n=n>>1;
    }
}