#include<bits/stdc++.h>
using namespace std;
void tower(int n,char src,char dest,char helper);
int main()
{
    int n;
    cin>>n;
    tower(n,'A','B','C');
    return 0;
}
void tower(int n,char src,char dest,char helper)
{
    if(n==0)
    return ;
    tower(n-1,src,helper,dest);
    cout<<"shift "<<n<<" to "<<dest<<endl;
    tower(n-1,helper,dest,src);
}