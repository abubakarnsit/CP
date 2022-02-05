#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
	    int k;
        cin>>n;
        cin>>k;
       if(k==1)
	   cout<<n<<endl;
	   else
	   {	   
		long long int h=n;
		long long int l=0;
		long long int ans=(l+h)/2;
		long long int mid;
		while(ans!=mid)
		{
         mid=ans;
		 if(pow(ans,k)<n)
		 l=ans;
		 else if(pow(ans,k)==n)
		 {
			 break;
		 }
		 else
         {
		 h=ans;
         }
		 ans=(l+h)/2;
		}
		cout<<ans<<endl;
	}
	}
}