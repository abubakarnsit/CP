#include<bits/stdc++.h>
using namespace std;
void count(int **arr,int,int,int ,int,string str,vector<string>&v);
int main() {
	int n,m;
	cin>>m>>n;
	vector<string>v2;
	string str="";
	vector<string>&v=v2;
	int **arr=new int*[n];
	for(int i=0;i<n;i++)
	arr[i]=new int[m];
	count(arr,0,0,n,m,str,v);
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<v.size();

}
void count(int **arr,int i,int j, int n,int m,string str,vector<string>&v)
{
	if(i<0||i>=n||j<0||j>=m)
	return ;
	if(i==n-1&&j==m-1)
	{
	v.push_back(str);
	return ;
	}
    string str1=str +'H';
    string str2=str +'V';
    count(arr,i+1,j,n,m,str1,v);
	count(arr,i,j+1,n,m,str2,v);
}