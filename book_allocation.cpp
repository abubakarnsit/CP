#include<iostream>
#include<limits.h>
using namespace std;
bool canadjust(int*arr,int mid, int students,int n);
int find(int*arr,int students,int n);
int main()
{
    int arr[]={10,20,30,40};
    int n=sizeof(arr)/sizeof(int);
    int numberofstudents=2;
    cout<<"min pages that can be assigned to each student is  "<<find(arr,numberofstudents,n-1)<<endl;
}

int find(int*arr,int students,int n)
{
    int ans=INT_MAX;
    int s=arr[n];
    int sum=0;
    for(int i=0;i<=n;i++)
    sum+=arr[i];
    int e=sum;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(canadjust(arr,mid,students,n))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

bool canadjust(int*arr,int mid, int students,int n)
{
    int stu=1;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(ans+arr[i]>mid)
        {
            stu++;
            if(stu>students)
            return false;
            ans=arr[i];
        }
        else
            ans =ans+arr[i];
    }
    return true;
}
