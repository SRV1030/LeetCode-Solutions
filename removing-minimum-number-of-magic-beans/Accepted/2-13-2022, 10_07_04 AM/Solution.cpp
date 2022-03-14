// https://leetcode.com/problems/removing-minimum-number-of-magic-beans

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long s=0,l=0,n=beans.size();
        for(auto&i:beans)s+=i;
        long long mn=s;
        sort(beans.begin(),beans.end());
        for(int i=0;i<n;i++){   
            mn=min(mn,l+(s-(n-i)*beans[i]));
            l+=beans[i];
            s-=beans[i];
        }            
        return mn;
    }
};