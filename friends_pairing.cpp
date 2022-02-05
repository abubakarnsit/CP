#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
    int n;
    cin>>n;
    long long int arr[n];
    arr[0]=1;
    arr[1]=2;
    arr[2]=4;
    for(int i=3;i<n;i++)
    {
     arr[i]=arr[i-1]+(i-1+1)*arr[i-2];
    }
    cout<<arr[n-1]<<endl;
	}
}