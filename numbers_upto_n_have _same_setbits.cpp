#include <iostream>
using namespace std;
int com(int,int);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    int arr[64]={0};
	    int a=__builtin_popcount(n);
	    int count=0;
	    int j=0;
	    while(n>0)
	    {
	        arr[j]=n&1;
	        j++;
	        count++;
	        n=n>>1;
	    }
        cout<<count<<endl;
        for(int i=count;i>0=;i++)
        cout<<arr[i];
        cout<<endl;
	    int b=a;
	    long long ans=0;
	    for(int h=j-1;j>=0;j--)
	    {
	        if(arr[j]==1)
	        {
	          ans=ans+com(h,b);
	          b--;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
int com(int a,int b)
{
    if(b>a)
    return 0;
    else if(a==b)
    return 1;
    else
    {
        int ans1=1;
        int ans2=1;
        for(int i=a;i>(a-b);i--)
        ans1*=i;
        for(int i=1;i<=b;i++)
        ans2*=i;
        cout<<ans1/ans2<<endl;
        return ans1/ans2;
    }
}