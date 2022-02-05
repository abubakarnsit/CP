#include<bits/stdc++.h>
using namespace std;
#define N 100000

void multiply(int *arr,int i,int&num)
{
    int carry=0;
    for(int j=0;j<num;j++)
    {
        int product=arr[j]*i+carry;
        arr[j]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        arr[num]=carry%10;
        carry=carry/10;
        num++;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[N];
	    memset(arr,0,sizeof(arr));
	    arr[0]=1;
	    int num=1;
	    for(int i=2;i<=n;i++)
        multiply(arr,i,num);
	    for(int i=num-1;i>=0;i--)
	        cout<<arr[i];
	    cout<<endl;
	    
	}
	return 0;
}
