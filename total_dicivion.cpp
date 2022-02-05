#include<iostream>
using namespace std;
#define ll long long
int main() {
	int t;
	cin>>t;
	int arr[]={2,3,5,7,11,13,17,19};
	int h=sizeof(arr)/sizeof(int);
	while(t--)
	{
		ll int n;
		cin>>n;
		int ans=0;
		for(ll int i=1;i<=((1<<h)-1);i++)
		{
			int k=0;
			int sign=__builtin_popcount(i);
			int deno=1;
            ll int j=i;
			while(j>0)
			{
				
				int last_bit=(j&1);
				if(last_bit)
				{
					deno=deno*arr[k];
				}
				k++;
				j=j>>1;
			}
			if(sign%2==0)
			{
				ans-=n/deno;
			}
			else
			{
				ans+=n/deno;
			}

		}

	cout<<ans<<endl;

	}
	return 0;
}