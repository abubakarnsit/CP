#include<iostream>
#include<vector>
using namespace std;
bool yes(vector<int>v,int sum,int i,bool included);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		int sum=0;
		bool included=false;
		if(yes(v,sum,0,included))
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}
bool yes(vector<int>v,int sum,int i,bool included)
{
	if(sum==0&&included)
	return true;
	if(i>=v.size())
	return false;
	return yes(v,sum+v[i],i+1,true)||yes(v,sum,i+1,included);
}