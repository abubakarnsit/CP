#include<bits/stdc++.h>
using namespace std;
bool possible(int mid,int*arr,int m,int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=arr[i];
        while(temp>mid)
        {
            temp=temp-mid;
            m=m-1;
        }
    }
    if(m>=0)
    return true;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    m=m-n;
    sort(arr,arr+n,greater<int>());
    int low=0;
    int high=arr[0];
    int ans;
    while(low<=high)
    {
      int mid=(low+high)/2;
      if(possible(mid,arr,m,n))
      {
          //ans=mid;
          cout<<mid<<",";
          high=mid-1;
      }
      else
      {
          low=mid+1;
      }  
    }
   cout<<endl<<ans<<endl;
}