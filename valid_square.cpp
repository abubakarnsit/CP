#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distance(vector<int>&p,vector<int>&p1)
    {
        return (p[0]-p1[0])*(p[0]-p1[0])+(p[1]-p1[1])*(p[1]-p1[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1=distance(p1,p2);
        int d2=distance(p1,p3);
        int d3=distance(p1,p4);
        int d4=distance(p2,p3);
        int d5=distance(p4,p3);
        int d6=distance(p4,p2);
        if(d1==0 or d2==0 or d3==0 or d4==0 or d5==0 or d6==0)
            return false;
        if(d1==d3 and d2==2*d1 and d4==d1)
            return true;
        if(d3==d2 and d1==2*d2 and d4==d6)
            return true;
        if(d1==d2 and d3==2*d1 and d6==d5)
            return true;
        return false;
    }
};
int main()
{
    vector<int>p1(2);
    vector<int>p2(2);
    vector<int>p3(2);
    vector<int>p4(2);
    cin>>p1[0]>>p1[1]>>p2[0]>>p2[1]>>p3[0]>>p3[1]>>p4[0]>>p4[1];
    Solution s;
    cout<<s.validSquare(p1,p2,p3,p4)<<endl;
}