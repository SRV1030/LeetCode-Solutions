// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    long long minimumTime(vector<int>& time, int tt) {
        long long res=-1,lo=1,hi=1e15;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long cur=0;
            for(auto t:time){
                cur+=mid/t;
                if(cur>=tt)break;
            }
            if(cur>=tt){
                res=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return res;
    }
};