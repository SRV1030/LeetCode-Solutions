class Solution {
public:
    bool pos(vector<int>& piles, int &h,int &m){
        int hi=0;
        for(auto&i:piles){
            hi+=(i/m)+(i%m!=0);
            if(hi>h) return false;
        }
        return hi<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int m=(l+r)>>1;
            if(pos(piles,h,m))r=m;
            else l=m+1;
        }
        return r;
    }
};