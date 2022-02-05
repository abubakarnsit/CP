#include<bits/stdc++.h>
using namespace std;
int lcs(string str1,string str2,int i,int j,vector<vector<int>>&dp)
{
    if(i>=str1.length() or j>=str2.length())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(str1[i]==str2[j])
    return dp[i][j]=1+lcs(str1,str2,i+i,j+1,dp);
    return dp[i][j]=max(lcs(str1,str2,i+1,j,dp),lcs(str1,str2,i,j+1,dp));
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    vector<vector<int>>dp(str1.size(),vector<int>(str2.size(),-1));
    cout<<lcs(str1,str2,0,0,dp)<<endl;
    for(int i=0;i<str1.size();i++)
    {
        for(int j=0;j<str2.size();j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}