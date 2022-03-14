// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n=a.size();
        if(n<=1) return false;
        unsigned long long int s=0,s2=0;        
        for(auto i:a)s+=i;  
        if(s%k==0) return true;          
        s2=s;        
        for(int i=0,j=n-1;i<n&&j>=0;i++,j--){
            s-=a[i];
            s2-=a[j];
            if(i<n-2 && s%k==0) return true;
            if(j>1 && s2%k==0) return true;
        }
        return false;
    }
};