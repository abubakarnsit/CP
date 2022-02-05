#include<iostream>
using namespace std;


int findbytopdown(int totallength,int*cost,int *dp)
{
    if(totallength==0)
    return 0;
    if(dp[totallength]!=0)
    return dp[totallength];
    int ans=0;
    for(int i=1;i<=totallength;i++)
    {
       int newans=cost[i]+findbytopdown(totallength-i,cost,dp);
       ans=max(ans,newans);
    }
    return dp[totallength]=ans;
}

int findbybottomup(int totallength,int *cost,int *dp)
{
    dp[0]=0;
    for(int i=1;i<=totallength;i++)
    {
      dp[i]=0;
      for(int j=1;j<=totallength;j++)
      {
          if(i-j>=0)
          dp[i]=max(dp[i],dp[i-j]+cost[j]);
      }
    }
    return dp[totallength];
}

int main()
{
    int totallength;
    cin>>totallength;
    int cost[totallength+1]={0};
    int dp[totallength+1]={0};
    for(int i=1;i<=totallength;i++)
    {
        cin>>cost[i];
    }
    cout<<findbybottomup(totallength,cost,dp)<<endl;
    cout<<findbytopdown(totallength,cost,dp)<<endl;

}
