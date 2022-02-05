#include<bits/stdc++.h>
using namespace std;
void print(long long int);
void fig(int);
int main()
{
    long long int n;
    cin>>n;
    print(n);
}
void print(long long int n)
{    
    if(n==0)
    return;
    print(n/10);
    fig(n%10);
}
void fig(int i)
{
    if(i==0)
    cout<<"zero ";
    if(i==1)
    cout<<"one ";
    if(i==2)
    cout<<"two ";
    if(i==3)
    cout<<"three ";
    if(i==4)
    cout<<"four ";
    if(i==5)
    cout<<"five ";
    if(i==6)
    cout<<"six ";
    if(i==7)
    cout<<"seven ";
    if(i==8)
    cout<<"eight ";
    if(i==9)
    cout<<"nine ";

}