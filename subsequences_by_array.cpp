#include<bits/stdc++.h>
using namespace std;
void subsequence(char *arr,char *arr1,int i,int j);
int main()
{
    char arr[1000];
    char arr1[1000];
    cin>>arr;
    subsequence(arr,arr1,0,0);
}
void subsequence(char *arr,char *arr1,int i,int j)
{
    if(arr[i]=='\0')
    {
        arr1[j]='\0';
        cout<<arr1<<endl;
        return;
    }
    arr1[j]=arr[i];
    subsequence(arr,arr1,i+1,j+1);
    subsequence(arr,arr1,i+1,j);
}