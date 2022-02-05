#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int offerings(int N, int arr[]){
        int arr1[N];
        int arr2[N];
        arr1[0]=1;
        for(int i=1;i<N;i++)
        {
            if(arr[i]>arr[i-1])
            {
            arr1[i]=arr1[i-1]+1;
            }
            else
            {
            arr1[i]=1;
            }
        }
        arr2[N-1]=1;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            arr2[i]=arr2[i+1]+1;
            else
            arr2[i]=1;
        }
        int ans=0;
        for(int i=0;i<N;i++)
            cout<<arr1[i]<<" ";
        cout<<endl;
        for(int i=0;i<N;i++)
            cout<<arr2[i]<<" ";
        cout<<endl;
        for(int i=0;i<N;i++)
        ans=ans+max(arr1[i],arr2[i]);
        return ans;
    }
};
int main(){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.offerings(N, arr)<<"\n";
    return 0;
}