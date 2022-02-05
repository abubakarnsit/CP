#include <iostream>
using namespace std;
bool can(int *arr,int ,int);
int main(){
int  a,b;
cin>>a>>b;
int arr[a];
for(int i=0;i<a;i++)
cin>>arr[i];
if(can(arr,a,b))
cout<<"true";
else
cout<<"false";
}
bool can(int *arr,int a,int b)
{
    if(b<0||b>=a)
    return false;
    if(arr[b]==0)
    return true;
    if(arr[b]!=0)
    {
        int ans;
        ans=arr[b];
        arr[b]=a+1;
        return(can(arr,a,b+ans)||can(arr,a,b-ans));
    }
}
