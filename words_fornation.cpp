#include <iostream> 
#include <cstring> 
using namespace std;  
int countDecoding(char *digits, int n,int*dp) 
{ 
    if (digits[0]=='0') 
          return 0; 
    if (n == 0 || n == 1) 
        return 1; 
     if(dp[n]!=-1)
     return dp[n];
    int count = 0;
    if (digits[n-1] > '0') 
        count +=  countDecoding(digits,n-1,dp); 
    if (digits[n-2]=='1'||(digits[n-2]=='2'&&digits[n-1]<'7')) 
        count+=countDecoding(digits,n-2,dp); 
    return dp[n]=count; 
} 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char digits[n]; 
        cin>>digits;
        int dp[n+1];
        for(int i=0;i<n+1;i++)
           dp[i]=-1;
        cout <<countDecoding(digits,n,dp)<<endl;
    }
    return 0; 
}