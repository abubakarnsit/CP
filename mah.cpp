
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k;
		cin>>i>>j>>k;
		std::string::iterator it = str.begin();
		std::string::iterator it2 =str.begin();
		 std::advance(it, i-1);
		  std::advance(it2, j);
		  cout<<*it<<" "<<*it2<<endl;
		std::rotate(it, it + k, it2);
		cout<<str<<endl;
	}
}
