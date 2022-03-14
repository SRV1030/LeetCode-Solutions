// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    bool checkpos(vector<int>& position,int dist,int balls){
        int ballsplaced=1;
        int cur=0;
        for(int i=1;i<position.size();i++){
            if(position[i]-position[cur]>=dist){
                cur=i;
                ballsplaced++;
            }
            if(ballsplaced==balls)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int l=1,h=p[p.size()-1]-p[0],mx=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(checkpos(p,mid,m)){
                mx=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return mx;
    }
};