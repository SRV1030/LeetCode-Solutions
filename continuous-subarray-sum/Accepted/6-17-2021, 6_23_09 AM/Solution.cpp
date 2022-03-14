// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n=a.size();
        if(n<=1) return false;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int s=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            s%=k;
            if(mp.count(s) && abs(i-mp[s])>1) return true;
            else if(!mp.count(s)) mp[s]=i;
        }
        return false;
    }
};