// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        v=vector<int>(w.size());
        v[0]=w[0];
        for(int i=1;i<w.size();i++)v[i]=v[i-1]+w[i];
    }
    
    int pickIndex() {
        int rnd=rand()%(v.back())+1;
        int l=0,r=v.size()-1;
        while(l<r){
            int m= (l+r)/2;
            if(v[m]==rnd)return m;
            else if(v[m]<rnd)l=m+1;
            else r=m;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */