#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n ;
	    cin>>n;
	    int cost[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>cost[i][j];
	        }
	    }
	    int dp[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i==0||j==0)
	            dp[i][j]=cost[i][j];
	            else if(i==0)
	            {
	                dp[i][j]=cost[i][j]+dp[i][j-1];
	            }
	            else if(j==0)
	            {
	                dp[i][j]=cost[i][j]+dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+cost[i][j];
	            }
	            
	        }
	    }
	    cout<<dp[n-1][n-1]<<endl;
	}
	return 0;
}