#include<iostream>
using namespace std;
#define N 100000
void replace(char *arr,int );
int main()
{
    char arr[N];
    cin>>arr;
    replace(arr,0);
    cout<<arr<<endl;
    return 0;
}
void replace(char arr[],int i)
{
    if(arr[i]=='\0' or arr[i+1]=='\0')
    return;
    if(arr[i]=='p' and arr[i+1]=='i')
    {
        int j=i+2;
        while(arr[j]!='\0')
        j++;
        while(j>=i+2)
        {
            arr[j+2]=arr[j];
            j--;
        }
        arr[i]='3';
        arr[i+1]='.';
        arr[i+2]='1';
        arr[i+3]='4';
        replace(arr,i+4);
    }
    else
    {
    replace(arr,i+1);
    }
    return;
}