#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	   long double arr[n+1];
	    arr[0]=1;
	    for(int i=0;i<n+1;i++)
	        arr[i]=arr[i-1]*(n-i+1)/i;
	    long double sum=0;
	    for(int i=0;i<=n;i++)
	    sum+=arr[i]*arr[i];
	    cout<<sum<<endl;
	}
	return 0;
}