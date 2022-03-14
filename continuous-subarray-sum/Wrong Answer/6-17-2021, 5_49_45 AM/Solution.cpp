// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        unsigned long long int s=0,s2=0;
        for(auto i:a)s+=i;
        int n=a.size();
        if(s==0 && n<=1) return false;
        if(s%k==0) return true;          
        s2=s;
        
        for(int i=0,j=n-1;i<n-1,j>0;i++,j--){
            s-=a[i];
            s2-=a[j];
            if(s%k==0 || s2%k==0) return true;
        }
        return false;
    }
};