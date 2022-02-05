#include<bits/stdc++.h>
using namespace std;
bool possible(int mid,int*arr,int p,int l)
{
    int sc=0;
    for(int i=0;i<l;i++)
    {
        
        int s=arr[i];
        int j=2;
        while(s<=mid)
        {
            sc++;
            s=s+(j*arr[i]);
            j++;
        }
    }
   // cout<<sc<<" "<<mid<<endl;
    if(sc>=p)
    return true;
    return false;
}
int main()
{
    int p,l;
    cin>>p>>l;
    int arr[l];
    for(int i=0;i<l;i++)
    {
        cin>>arr[i];
    }
    int s=0;
    int e=100000;
    int ans=e;
    while(s<=e)
    {
      int mid=(s+e)/2;
      if(possible(mid,arr,p,l))
      {
          ans=min(ans,mid);
          e=mid-1;
      }
      else
      {
          s=mid+1;
      }
      
    }
    cout<<ans<<endl;
   
}