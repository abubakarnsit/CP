#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n);
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    arr[0]=0;
    for(int i=1;i<=n;i++)
    arr[i]=arr[i-1]+arr[i];
    print(arr,n+1);
    for(int i=0;i<n+1;i++)
    arr[i]=arr[i]%k;
    print(arr,n+1);
    int arr1[k]={0};
    for(int i=0;i<=n;i++)
        arr1[arr[i]]++;
    int ans=0;
    for(int i=0;i<k;i++)
    ans=ans+(arr1[i]*(arr1[i]-1))/2;
    cout<<ans<<endl;
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}