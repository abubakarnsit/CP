#include<bits/stdc++.h>
using namespace std;
class graph
{
 int v;
 int**mat;
public:
   graph(int a)
   {
    v=a;
    mat=new int*[v];
    for(int i=0;i<v;i++)
    mat[i]=new int[v];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
        mat[i][j]=1000000;
        if(i==j)
        mat[i][j]=0;
        }
    }
   }
   void addedge(int a,int b,int weight,bool t)
   {
       if(t==true)
       {
       mat[a-1][b-1]=weight;
       mat[b-1][a-1]=weight;
       }
       else
       {
        mat[a-1][b-1]=weight;
       }
       
   }
   void print()
   {
     for(int i=0;i<v;i++)
     {
         for(int j=0;j<v;j++)
         cout<<mat[i][j]<<"  ";
         cout<<endl;
     }
     cout<<endl;
   }
   void floyd()
   {
        for (int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                for(int k=0;k<v;k++)
                {
                    if(mat[i][j]+mat[j][k]<mat[i][k])
                     mat[i][k]=mat[i][j]+mat[j][k];
                }
            }
        }
   }
};
int main()
{
    int n;
    char a;
    bool b;
    cout<<" enter if graph is bidirectional or not (Y/N) ";
    cin>>a;
    if(a=='y'||a=='Y')
    b=true;
    else
    b=false;
    cin>>n;
    graph g(n);
    g.print();
    g.addedge(1,2,1,b);
    g.addedge(2,3,2,b);
    g.addedge(1,4,3,b);
    g.addedge(3,4,4,b);
    g.addedge(4,5,5,b);
    g.addedge(3,5,2,b);
    g.print();
    g.floyd();
    g.print();
}