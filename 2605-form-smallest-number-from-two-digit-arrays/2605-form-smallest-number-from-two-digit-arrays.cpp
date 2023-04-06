class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int>f(10);
        int m1=10,m2=10,r=10;
        for(auto&i:nums1){
            f[i]=1;
            m1=min(m1,i);
        }
        for(auto&i:nums2){
            if(f[i]==1)r=min(r,i);
            m2=min(m2,i);
        }   
        if(r!=10) return r;
        return min(m1,m2)*10+max(m1,m2);
    }
};