#include<iostream>
using namespace std;
void print(int*arr,int);
int main() {
	int a,b;
	cin>>a>>b;
	int arr[a+1]={0};
	while(b--)
	{
		int i,j,val;
		cin>>i>>j>>val;
		arr[i]=arr[i]+val;
		arr[j+1]=arr[j+1]-val;
	}
	for(int i=1;i<=a;i++)
          arr[i]=arr[i-1]+arr[i];
	int ans=0;
	for(int i=0;i<a;i++)
	{
		if(arr[i]>ans)
		ans=arr[i];
	}
	cout<<ans;
	return 0;
}
void print(int* arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}