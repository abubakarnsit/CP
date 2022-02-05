#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}
bool isafe(int i,int j,int n,int m)
{
    if(i>=0 and i<n and j>=0 and j<m)
    return true;
    return false;
}
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,-1,0,1,-1,0,1};
void dfs(int i,int j,int n,int m,vector<int>A[],bool**mat)
{
    mat[i][j]=true;
    for(int l=0;l<8;l++)
    {
        if(isafe(i+dx[l],j+dy[l],n,m) and mat[i+dx[l]][j+dy[l]]==false and A[i+dx[l]][j+dy[l]]==1)
        dfs(i+dx[l],j+dy[l],n,m,A,mat);
    }
}
int findIslands(vector<int> A[], int N, int M) {
int count=0;
bool** mat=new bool*[N];
for(int i=0;i<N;i++)
mat[i]=new bool[M];
for(int i=0;i<N;i++)
{
    for(int j=0;j<M;j++)
    mat[i][j]=false;
}
for(int i=0;i<N;i++)
{
    for(int j=0;j<M;j++)
    {
        if(mat[i][j]==false and A[i][j]==1)
        {
            dfs(i,j,N,M,A,mat);
            count++;
        }
    }
}
for(int i=0;i<N;i++)
{
    for(int j=0;j<M;j++)
    cout<<A[i][j]<<" ";
    cout<<endl;
}
cout<<endl;
for(int i=0;i<N;i++)
{
    for(int j=0;j<M;j++)
    cout<<mat[i][j]<<" ";
    cout<<endl;
}
cout<<endl;
return count;
}