#include<bits/stdc++.h>
using namespace std;
void mergesort(int*arr,int,int);
void merge(int* arr,int ,int,int);
void print(int* arr,int);
int	main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergesort(arr,0,n);
    print(arr,n);
    return 0;
}
void mergesort(int *arr,iōnt s,int e)
{
    if(s<e)
    {
    int mid=(s+e)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e,mid);
    }
}
void merge(int *arr,int s,int e,int mid)
{
    int temp[1000000];
    int i=s;
    int k=s;
    int j=mid+1;
    while(i<=mid&&j<e)
    {
        if(arr[i]<=arr[j])
        {
        temp[k]=arr[i];
        k++;
        i++;
        }
        else
        {
        temp[k]=arr[j];
        k++;
        j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<e)
    {       
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int a=s;a<e;a++)
    arr[a]=temp[a];
}
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
