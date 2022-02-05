#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int n);
int mx(int a,int b);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int left[n];
    int ma=arr[0];
    left[0]=0;
    for(int i=1;i<n;i++)
    {
        left[i]=ma;
        if(arr[i]>ma)
        ma=arr[i];
    }
    print(left,n);
    int right[n];
    int m=arr[n-1];
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
        int k=mx(left[i],right[i]);
        cout<<mx<<" ";
        ans=ans+(k-arr[i]);
    }
    cout<<ans;

}
int mx(int a,int b)
{
    if(a>b)
        return b;
    return a;
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
