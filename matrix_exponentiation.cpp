#include<iostream>
using namespace std;

int**matrixmultiply(int**mat1,int**mat2,int n);
int**find(int**mat,int pow,int n);
void print(int**mat,int n);

int** matrixmultiply(int **mat1,int**mat2,int n)
{
    int **matr=new int *[n];
    for(int i=0;i<n;i++)
    {
        matr[i]=new int [n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
             matr[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
               matr[i][j]+=mat1[i][k]*mat2[k][j]; 
            }           
        }
    }
    return matr;
}

int**find(int**mat,int power,int n)
{
    if(power==1)
    return mat;
    int**res=find(mat,power/2,n);
    if(n&1==1)
    return matrixmultiply(matrixmultiply(res,res,n),mat,n);
    return matrixmultiply(res,res,n); 
}


void print(int**mat,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int** mat=new int*[n];
    for(int i=0;i<n;i++)
    {
        mat[i]=new int [n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    print(mat,n);
    int power;
    cin>>power;
    int **ans=find(mat,power,n);
    print(ans,n);

}
