#include<iostream>
#include<climits>
using namespace std;
int find(int amount,int *dp,int* coin,int n);
int find2(int amount,int*coin,int n);
int main()
{
    int n;
    cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    int amount;
    cin>>amount;
    int dp[amount+1]={0};
    cout<<find(amount,dp,coin,n)<<endl<<endl<<endl;
    cout<<find2(amount,coin,n)<<endl;
}
int find(int amount,int *dp,int* coin,int n)
{
    if(amount==0)
    return 0;
    if(dp[amount]!=0)
    return dp[amount];
    int ans=INT_MAX;
    for(int i=1;i<n;i++)
    {
        if(amount-coin[i]>=0)
        {
            int subprob=find(amount-coin[i],dp,coin,n);
            ans=min(ans,subprob+1);
        }
    }
    return dp[amount]=ans;
}
int find2(int amount,int*coin,int n)
{
    int dp[amount+1]={0};
    for(int i=0;i<=amount;i++)
    cout<<dp[i]<<" ";
    cout<<endl<<endl;
    for(int i=1;i<=amount;i++)
    {
        dp[i]=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if((amount-coin[j])>=0)
            {
                cout<<dp[amount-coin[j]]+1<<",";
                dp[i]=min(dp[i],dp[amount-coin[j]]+1);
            }
        }
        cout<<endl;
    }
    for(int i=0;i<=amount;i++)
    cout<<dp[i]<<" ";
    cout<<endl;
    return dp[amount];
}