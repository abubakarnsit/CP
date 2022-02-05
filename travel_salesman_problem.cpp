#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
int tsp(int mask,int pos,int **cost,int visited_all,int n,int**dp)
{
    if(mask==visited_all)
    {
        return cost[pos][0];
    }
    if(dp[mask][pos]!=-1)
    return dp[mask][pos];
    int ans=1000000;;
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int newans=cost[pos][city]+tsp(mask|(1<<city),city,cost,visited_all,n,dp);
            ans=min(ans,newans);
            cout<<ans<<endl;
        }
    }
    return dp[mask][pos]=ans;

}
void print(int**arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {    
            if(i==j)
            arr[i][j]=0;
            else
            {
                arr[i][j]=100000;
            }           
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        arr[x][y]=w;
        arr[y][x]=w;
    }
    int jk=pow(2,n);
    int **dp=new int*[jk];
    for(int i=0;i<jk;i++)
    {
        dp[i]=new int[n];
    }
    for(int i=0;i<jk;i++)
    {
        for(int j=0;j<n;j++)
        dp[i][j]=-1;

    }
    int visited_all=(1<<n)-1;
    int ans=tsp(1,0,arr,visited_all,n,dp);
    print(arr,n);
    cout<<ans<<endl;
    for(int i=0;i<jk;i++)
    {
        for(int j=0;j<n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}