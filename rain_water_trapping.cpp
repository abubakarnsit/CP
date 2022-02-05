#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int left[n];
    int m=arr[0];
    left[0]=0;
    for(int i=1;i<n;i++)
    {
        left[i]=m;
        if(arr[i]>m)
        m=arr[i];
    }
    print(left,n);
    int right[n];
    m=arr[n-1];
    right[n-1]=0;
    for(int i=n-1;i>=0;i--)
    {
        right[i]=m;
        if(arr[i]>m)
        m=arr[i];
    }
    print(right,n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int k=min(left[i],right[i]);
        if(k>arr[i])
        ans=ans+(k-arr[i]);      
    }
    cout<<endl<<ans;
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
