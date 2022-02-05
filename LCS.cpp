#include<iostream>
using namespace std;
int lcs(string a, string b,int i,int j,int dp[][100]);
void print(string str1,string str2,int &len,int i,int j,int dp[][100]);
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            
            dp[i][j]=-1;
        }
    }
    int len=lcs(str1,str2,0,0,dp);
    cout<<len<<endl;
    print(str1,str2,len,0,0,dp);
    return 0;
}
int lcs(string a, string b,int i,int j,int dp[][100])
{
    if(i>=a.length()||j>=b.length())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int len=0;
    if(a[i]==b[j])
    {
        len=1+lcs(a,b,i+1,j+1,dp);
    }
    else
    {
        len=len+max(lcs(a,b,i+1,j,dp),lcs(a,b,i,j+1,dp));
    }
    return dp[i][j]=len;  
}
void print(string str1,string str2,int &len,int i,int j,int dp[][100])
{
    if(len<=0)
    return;
    if(str1[i]==str2[j])
    {
    cout<<str1[i];
    len=len-1;
    print(str1,str2,len,i+1,j+1,dp);
    }
    else if(dp[i+1][j]>dp[i][j+1])
    print(str1,str2,len,i+1,j,dp);
    else
    {
      print(str1,str2,len,i,j+1,dp);
    }
    return;
    
}