// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        unsigned long long int s=0,s2=0;
        for(auto i:a)s+=i;
        if(s%k==0) return true;  
        if(s==0) return false;
        s2=s;
        int n=a.size();
        for(int i=0,j=n-1;i<n-1,j>0;i++,j--){
            s-=a[i];
            s2-=a[j];
            if(s%k==0 || s2%k==0) return true;
        }
        return false;
    }
};