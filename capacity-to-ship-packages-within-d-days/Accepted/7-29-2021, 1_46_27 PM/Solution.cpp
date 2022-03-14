// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool isValid(vector<int>& wts, int d,int mx){
        int s=0;
        for(auto i:wts){
            s+=i;
            if(s>mx){
                d--;
                s=i;
            }
            if(!d) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& wts, int days) {
        int l=0,h=0;
        for(auto i:wts){
            l=max(l,i);
            h+=i;
        }
        int res=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(isValid(wts,days,m)){
                res=m;
                h=m-1;
            }
            else l=m+1;
        }
        return res;
    }
};