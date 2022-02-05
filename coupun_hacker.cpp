#include<bits/stdc++.h>
using namespace std;
bool possible(long int mid,long int n,long int m,long int x,long int y)
{
    if((m+(n-mid)*y)>=(mid*x))
    return true;
    return false;
}
int main()
{
    long int n,m,x,y;
    cin>>n>>m>>x>>y;
    long int s=0;
    long int e=n;
    long int ans=0;
    while(s<=e)
    {
      long int mid=(s+e)/2;
      if(possible(mid,n,m,x,y))
      {
          ans=max(ans,mid);
          s=mid+1;
      }
      else
      {
          e=mid-1;
      }
    }
	cout<<ans<<endl;
	return 0;
}