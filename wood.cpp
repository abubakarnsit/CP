#include<bits/stdc++.h>
using namespace std;
   bool solvehelp(vector<int>& v,int diff,int K){
     
        int n=v.size();
        int prev=0;
        int removed=0;
        for(int i=1;i<n&&removed<K;i++){
            if(i==n-1 || v[i+1]-v[prev]>diff){
                if(v[i]-v[prev]>diff)return false;
                prev=i;
            }
            else removed++;
        }
        return (removed==K);
    }  
    int solve(int n,vector<int> v,int K){
        
        int hi=v.back()-v[0];
        int lo=0;
        
        for(int i=0;i+1<v.size();i++)lo=max(lo,v[i+1]-v[i]);
        
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(solvehelp(v,mid,K))hi=mid;
            else lo=mid+1;
        }
        return lo;        
    }
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cin>>k;
    cout<<solve(n,v,k)<<endl;
    
    return 0;
}