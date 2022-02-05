#include<bits/stdc++.h> 
  
using namespace std; 
  
// Function returns the minimum number of swaps 
// required to sort the array 
int minSwaps(int arr[], int n) 
{ 
    pair<int, int> p[n]; 
    for (int i = 0; i < n; i++) 
    { 
        p[i].first = arr[i]; 
        p[i].second = i; 
    } 
    sort(p, p + n);    
    int ans = 0; 
    vector<bool> visited(n, false); 
    for (int i = 0; i < n; i++) 
    { 
        if (p[i].second == i||visited[i]==true) 
            continue; 
        int len = 0; 
        int j = i; 
        while (!visited[j]) 
        { 
            visited[j] = true; 
            len++;
            j = p[j].second; 
            
        } 
        if (len > 0) 
        { 
            ans += (len - 1); 
        } 
    } 
    return ans; 
} 
  
// Driver program to test the above function 
int main() 
{ 
    int arr[] = {101,758,315,730,472,619,460,479}; 
    int n = (sizeof(arr) / sizeof(int)); 
    cout << minSwaps(arr, n); 
    return 0; 
} 