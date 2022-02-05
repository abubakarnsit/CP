#include<bits/stdc++.h>
using namespace std;
bool canadjust(int*arr,int mid, int m,int n)
{
    int t=1,ans=0;
    for(int i=0;i<=n;i++)
    {
        if(ans+arr[i]>mid)
        {
            t++;
            if(t>m)
            return false;
            ans=arr[i];
        }
        else
            ans =ans+arr[i];
    }
    return true;
}
int find(int*arr,int m,int n)
{
    int ans=INT_MAX;
    int s=0,sum=0;
    for(int i=0;i<=n;i++)
	{
		s=max(s,arr[i]);
		sum+=arr[i];
	}
    int e=sum;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(canadjust(arr,mid,m,n))
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

int main()
{
	int n,m;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>m;
	int ans=find(arr,m,n-1);
	if(ans==INT_MAX)
	cout<<-1<<endl;
	else
	cout<<ans<<endl;

}