// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int pos(vector<int>& w, int d,int m){
        int c=1,s=0;
        for(int i=0;i<w.size();i++){
            s+=w[i];
            if(s>m){
                c++;
                s=0;
                i--;
            }
            if(c>d) return false;
        }
        return c<=d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l=w[0],h=0;
        for(auto&i:w){
            h+=i;
            if(i>l)l=i;
        }
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(pos(w,d,m)){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};