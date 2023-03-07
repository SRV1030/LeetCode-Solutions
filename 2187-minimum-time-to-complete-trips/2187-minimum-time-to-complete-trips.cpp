class Solution {
public:
    bool pos(vector<int>& time,long long tT,long long m){
        long long ts=0;
        for(auto&i:time){
            ts+=(m/i);
            if(ts>=tT) return true;
        }
        return ts>=tT;
    }
    long long minimumTime(vector<int>& time, int tT) {
        long long l=1,h=1e15;
        long long m=0,res=0;
        while(l<=h){
            long long m=l+(h-l)/2;
            if(pos(time,tT,m)){
                res=m;
                h=m-1;
            }
            else l=m+1;
        }
        return res;
    }
};