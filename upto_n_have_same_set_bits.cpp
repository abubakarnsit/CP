#include <iostream>
using namespace std;
long long int com(int,int);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    int arr[64]={0};
	    int a=__builtin_popcount(n);
        cout<<a<<endl;
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
        for(int i=count-1;i>=0;i--)
        cout<<arr[i];
        cout<<endl<<endl;
	    int b=a;
	    long long int ans=0;
	    for(int h=count-1;h>=0;h--)
	    {
	        if(arr[h]==1)
	        {
	          ans=ans+com(h,b);
	          b--;
	        }
	    }
	    
	    cout<<ans<<endl;
	}
	return 0;
}
long long int com(int a,int b)
{
    if(b>a)
    return 0;
    else if(b<=0)
    return 0;
    else if(a==b)
    return 1;
    else
    {
        long long int ans1=1;
        long long int ans2=1;
        for(int i=a;i>(a-b);i--)
        ans1*=i;
        for(int i=1;i<=b;i++)
        ans2*=i;
        cout<<a<<" "<<b<<"  "<<ans1/ans2<<endl;
        return ans1/ans2;
    }
}