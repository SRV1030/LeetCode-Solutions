// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(min(n1,n2)*6<max(n1,n2)) return -1;
        int s1=0,s2=0;
        for(auto&i:nums1)s1+=i;
        for(auto&i:nums2)s2+=i;
        if(s1==s2) return 0;
        if(s2>s1){
            swap(nums1,nums2);
            swap(n1,n2);
            swap(s1,s2);
        }
        vector<int> diff;
        int c=0,dif=s1-s2;
        for(auto&i:nums1)diff.emplace_back(i-1);
        for(auto&i:nums2)diff.emplace_back(6-i);
        sort(diff.begin(),diff.end(),greater<int>());
        for(auto&d:diff){
            // cout<<dif<<" "<<d<<"\n";
            dif-=d;
            c++;
            if(dif<=0) return c;
        }
        return -1;
    }
};