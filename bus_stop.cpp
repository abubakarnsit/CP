#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    arr[i]=new int[3];
    for(int i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    int dist[n];
    int parent[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        parent[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
        }
    }
}