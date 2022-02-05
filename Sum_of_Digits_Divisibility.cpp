#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a=n;
	    int sum=0;
	    while(n>0)
	    {
	        sum=sum+n%10;
	        n=n/10;
	    }
	    if(a%sum==0)
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}