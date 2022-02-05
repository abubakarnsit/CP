#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1]={0};
        for(int i=0;i<n;i++)
        {
            long int a;
            cin>>a;
            if(a>0)
            arr[a]++;
        }
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==0)
            {
                if(flag==0)
                cout<<i<<endl;
                flag++;
            }
        }
    }
    
    return 0;
}