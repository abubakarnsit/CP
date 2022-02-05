#include<bits/stdc++.h>
using namespace std;
int main()
{
    char douwanttorepeat='Y';
    int size1,size2;//sizes of two array decleration
    do{
    cout<<"enter the size of first array character "<<endl;
    cin>>size1;
    char array1[size1];
    cout<<"Enter the characters of array"<<endl;
    for(int i=0;i<size1;i++)
    cin>>array1[i];
    cout<<"enter the size of second array character "<<endl;
    cin>>size2;
    char array2[size2];
    cout<<"Enter the characters of second array"<<endl;
    for(int i=0;i<size2;i++)
    cin>>array2[i];
    for(int i=0;i<min(size1,size2);i++)
    {
        //swapping the characters
        char c=array1[i]; 
        array1[i]=array2[i];
        array2[i]=c;
    }
    cout<<"arrays after maximum swaps possible :"<<endl;
    cout<<"array1: ";
    for(int i=0;i<size1;i++)
    cout<<array1[i]<<" ";
    cout<<endl;
     cout<<"array2: ";
    for(int i=0;i<size2;i++)
    cout<<array2[i]<<" ";
    cout<<endl;
    char d;
    cout<<"Do you want to exit(press e or E for that) otherwise press any other key: ";
    cin>>d;
    if(d=='e' or d=='E')
    douwanttorepeat='N';
    }while(douwanttorepeat!='N');
}