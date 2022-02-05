#include<iostream>
using namespace std;
#define N 100000
void mergesort(int arr[],int s,int e);
void merge(int arr[],int s,int e);
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 {
     cin>>arr[i];
 }
 mergesort(arr,0,n-1);
 for(int i=0;i<n;i++)
 {
     cout<<arr[i]<<" ";
 }
 return 0;
}
void mergesort(int arr[],int s,int e)
{
    if(s>=e)
    return;
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}
void merge(int arr[],int s,int e)
{
    int temp[N];
    int i=s;
    int mid=(s+e)/2;
    int j=mid+1;
    int k=s;
    while(i<=mid and j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }        
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=e)
    {
        temp[k++]=arr[j++];
    }
    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i];
    }
}