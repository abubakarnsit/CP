// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int [], int );

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		
		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];
		
		cout<< findLongestConseqSubseq(a, n)<<endl;
		
	}
	return 0;
}// } Driver Code Ends




// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
    sort(arr,arr+n);
    int count=1;
    int prev=arr[0];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==prev+1||arr[i]==prev)
        {
            count++;
            ans=max(count,ans);
        }
        else
        {
            count=1;
        }
        prev=arr[i];
    }
    return ans;
}