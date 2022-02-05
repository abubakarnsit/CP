#include<iostream>
using namespace std;
bool equivalent(string str1,string str2);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		if(equivalent(str1,str2))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
        cout<<endl<<endl;
	}
	return 0;
}
bool equivalent(string str1,string str2)
{
    cout<<str1.length()<<endl<<str2.length()<<endl;
	if(str1==str2)
	return true;
	if(str1.length()%2==1||str2.length()%2==1)
	return false;
	string a1=str1.substr(0,str1.length()/2);
	string a2=str1.substr((str1.length()/2),str1.length()/2);
	string b1=str2.substr(0,str2.length()/2);
	string b2=str2.substr((str2.length()/2),str2.length()/2);
	return ((equivalent(a1,b1)&&equivalent(a2,b2))||(equivalent(a1,b2)&&equivalent(a2,b1)));
}