// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int dist=INT_MAX,ind=-1,j=0;
        for(auto&i:points){
            if(i[0]==x || i[1]==y){
                int d=abs(x-i[0])+abs(y-i[1]);
                if(d<dist){
                    dist=d;
                    ind=j;
                }
            }
            j++;
        }
        return ind;
    }
};