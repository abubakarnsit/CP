#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,2,5,87,56};
    int key;
    int n=sizeof(arr)/sizeof(int);
    cin>>key;
    auto it=find(arr,arr+n,key);
    if((it-arr)==n)
    {
        cout<<"element not found";
    }
    else
    cout<<it-arr<<endl;
    int arr2[]={2,3,4,5,78,90,90,90,890,8900};
    int n2=sizeof(arr2)/sizeof(int);
    int key2;
    cin>>key2;
    bool find=binary_search(arr2,arr2+n2,key2);
    if (find)
    {
       cout<<"element found "<<endl; 
    }
     auto it2=lower_bound(arr2,arr2+n2,key2);
     cout<<"at index "<<it2-arr2<<endl;
     int* it3=upper_bound(arr2,arr2+n2,key2);
     cout<<"with frequnecy "<<it3-it2;







}
