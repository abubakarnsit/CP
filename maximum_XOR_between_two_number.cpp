#include<iostream>
using namespace std;
int main () {
	long long int x,y;
	cin>>x>>y;
	int ch1[64]={0};
	int ch2[64]={0};
	int j=0;
	while(x>0||y>0)
	{
		int last1=x&1;
		int last2=y&1;
		ch1[j]=last1;
		ch2[j]=last2;
		j++;
		x=x>>1;
		y=y>>1;
       
	}
    cout<<"binary represenation of x "<<endl;
	for(int a=63;a>0;a--)
	{
		cout<<ch1[a];
	}
	cout<<endl;
    cout<<"binary represenation of y "<<endl;
	for(int a=63;a>0;a--)
	{
		cout<<ch2[a];
	}
	cout<<endl;
    cout<<"first different bit"<<endl;
	int k;
	for (k=63;k>=0;)
	{
		if(ch1[k]==ch2[k])
		k--;
		else
		break;
	}
	cout<<k<<endl;
	long long int ans=0;
	long long int p=1;
	for (int i=0;i<=k;i++)
	{
		ans+=p;
		p=p*2;

	}
	cout<<"max xor between two numbers "<<ans;
	return 0;
}