// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& sts, vector<int>& sds) {
        int cnt[2]={0};
        for(int&i:sts)cnt[i]++;
        int k=0,n=sts.size();
        for(;k<n && cnt[sds[k]]>0;k++)cnt[sds[k]]--;
        return n-k;
    }
};