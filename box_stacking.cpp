#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
}
struct triplet
{
    int a,b,c;
};
bool sortby(triplet d,triplet e)
{
    return (d.a*d.b>e.a*e.b);
}
int maxHeight(int height[],int width[],int length[],int n)
{
    vector<triplet>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({height[i],width[i],length[i]});
        v.push_back({height[i],length[i],width[i]});
        v.push_back({width[i],height[i],length[i]});
        v.push_back({width[i],length[i],height[i]});
        v.push_back({length[i],width[i],height[i]});
        v.push_back({length[i],height[i],width[i]});
    }
    sort(v.begin(),v.end(),sortby);
   /* for(int i=0;i<v.size();i++)
    {
        cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].c<<endl;
    }*/
    int arr[v.size()];
    for(int i=0;i<v.size();i++)
    {
        arr[i]=v[i].c;
    }
    for(int i=0;i<v.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    for(int i=1;i<v.size();i++)
    {
        int ans=arr[i];
        for(int j=0;j<i;j++)
        {
            if(v[i].a<v[j].a and v[i].b<v[j].b)
            {
                ans=max(ans,arr[i]+arr[j]);
            }
        }
        arr[i]=ans;
    }
   int ans2=0;
   for(int i=0;i<v.size();i++)
   {
       ans2=max(ans2,arr[i]);
   }
   return ans2;
}