#include<bits/stdc++.h>
using namespace std;
bool gtbit(int,int);
void updatebit(int i,int j,int& n);
int main()
{
int a;
cin>>a;
cout<<(a&1)<<endl;
int i=0;
cin>>i;
cout<<gtbit(i,a)<<endl;
int v,j;
cout<<"update the bit to 1 or 0 and at the position ??"<<endl;
cin>>v>>j;
cout<<gtbit(v-1,a)<<endl;
updatebit(v-1,j,a);
cout<<a<<endl;
cout<<gtbit(v-1,a)<<endl;

if((a&1)==0)
    cout<<"even"<<endl;
else
    cout<<"odd"<<endl;

}
bool gtbit(int i,int n)
{
    return((n&(1<<i)));
}
void updatebit(int v,int j,int& n)
{
n=(n&(~(1<<v)));
n=(n|(j<<v));
}