#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        cin>>arr[i][j];
	    }
	    long long int path[n][n];
	    long long int cost[n][n];
	    path[0][0]=1;
	    for(int i=1;i<n;i++)
	    {
	        if(arr[0][i-1]==3 or arr[0][i-1]==1)
	        {
	            path[0][i]=path[0][i-1];
	        }
	        else path[0][i]=0;
	    }
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i-1][0]==2 or arr[i-1][0]==3)
	        {
	            path[i][0]=path[i-1][0];
	        }
	        else path[i][0]=0;
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	            path[i][j]=0;
	        }
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	           if(arr[i-1][j]==2 or arr[i-1][j]==3)
	           path[i][j]+=path[i-1][j];
	           if(arr[i][j-1]==1 or arr[i][j-1]==3)
	           path[i][j]+=path[i][j-1];
	           
	        }
	    }
	    cost[0][0]=arr[0][0];
	    for(int i=1;i<n;i++)
	    {
	        if((arr[0][i-1]==3 or arr[0][i-1]==1) and path[0][i-1]!=0)
	        cost[0][i]=cost[0][i-1]+arr[0][i];
	        else
	        cost[0][i]=0;
	    }
	    for(int i=1;i<n;i++)
	    {
	        if((arr[i-1][0]==3 or arr[i-1][0]==2) and path[i-1][0]!=0)
	        cost[i][0]=cost[i-1][0]+arr[i][0];
	        else
	        cost[i][0]=0;
	    }
	    for(int i=1;i<n;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	            int d=0,e=0;
	            if((arr[i][j-1]==3 or arr[i][j-1]==1) and path[i][j-1]!=0)
	            d=cost[i][j-1];
	            if((arr[i-1][j]==3 or arr[i-1][j]==2) and path[i-1][j]!=0)
	            e=cost[i-1][j];
	            cost[i][j]=max(d,e)+arr[i][j];
	            
	        }
	    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<path[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<cost[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
	    cout<<path[n-1][n-1]<<" "<<cost[n-1][n-1]<<endl;
	}
	return 0;
}