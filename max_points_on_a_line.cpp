#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int>findslope(int x1,int y1,int x2,int y2)
    {
        int dx=x2-x1;
        int dy=y2-y1;
        int gcd=__gcd(dx,dy);
        dx=dx/gcd;
        dy=dy/gcd;
        return make_pair(dy,dx);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<pair<int, int>, int>maps;
        int ans=1;
        for(int i=0;i<n-1;i++)
        {
            maps.clear();
            int copy=0;
            int tempans=0;
            int x1=points[i][0];
            int y1=points[i][1];
            pair<int,int>slope;
            for(int j=i+1;j<n;j++)
            {
                
                int x2=points[j][0];
                int y2=points[j][1];
                if(x1==x2 and y1==y2)
                {
                   copy++;
                    continue;
                }
                slope=findslope(x1,y1,x2,y2);
                if(maps.find(slope)==maps.end())
                {
                    maps[slope]=2;
                }
                else
                {
                    maps[slope]++;
                }
                tempans=max(tempans,maps[slope]);
            }
            ans=max(ans,tempans+copy);    
        }
        return ans;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>vec[i][0]>>vec[i][0];
    Solution s;
    int ans=s.maxPoints(vec);
    cout<<ans<<endl;
    return 0;

}