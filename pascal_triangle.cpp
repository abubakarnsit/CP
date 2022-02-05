#include<iostream>
using namespace std;
int main() {
int n ;
cin>>n;
for(int i=n;i>=0;i--)
{
   for(int j=0;j<=i-1;j++)
   cout<<" ";
   int f=n-i-1;
   int arr[n+1];
    arr[0]=1;
	for(int i=1;i<n+1;i++)
	{
		arr[i]=i*arr[i-1];
	}
   for(int k=0;k<=f;k++)
   {
	   int g=arr[f]/(arr[k]*arr[f-k]);
	   cout<<g<<" ";
   }
   cout<<endl;
   
}
}