/*language used is c++*/
#include<bits/stdc++.h>
using namespace std;

void letssort(int*arr,int n)
{
    int l=0;
    int h=n-1;
    int mid=0;
    while(mid<=h)
    {
        switch(arr[mid])
        {
            case 0:
                swap(arr[l++],arr[mid++]);
                break;
            case 1:
               mid++;
               break;
            case 2:
                swap(arr[mid],arr[h--]);
                break;

        }
    }
}
int main()
{
    int n;                // size of array
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    letssort(arr,n);
    for(int i=0;i<n;i++)      // printing the array
    cout<<arr[i]<<" ";
    return 0;
}


/* time complexity:O(n)
space complexity:O(1)
*/
