// https://leetcode.com/problems/minimum-area-rectangle

class Solution {
public:
    unordered_map<int,unordered_map<int,bool>>mp;
    int minAreaRect(vector<vector<int>>& points) {
        for(auto& i:points)mp[i[0]][i[1]]=true;
        int mn=INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                if(x1==x2 || y1==y2) continue;
                int x3 = x1, y3 = y2, x4 = x2, y4 = y1;
                if(mp[x3][y3] && mp[x4][y4]) mn=min(mn,abs(x1-x2)*abs(y1-y2));
            }
        }
        return mn==INT_MAX?0:mn;
    }
};