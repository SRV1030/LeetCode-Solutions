// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int lct=0;
        double t=0;
        for(int i=0;i<c.size();i++){
            if(lct>c[i][0]){
                t+=lct+c[i][1]-c[i][0];
                lct+=c[i][1];
            }else{
                t+=c[i][1];
                lct=c[i][1]+c[i][0];
            }
        }
        return  t/c.size();
    }
};