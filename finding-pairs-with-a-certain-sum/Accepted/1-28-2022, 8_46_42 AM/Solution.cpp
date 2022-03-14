// https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
public:
    vector<int>m1,m2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        m1=nums1;
        m2=nums2;
        for(auto&i:m2)mp[i]++;
    }
    
    void add(int index, int val) {
        mp[m2[index]]--;
        m2[index]+=val;
        mp[m2[index]]++;
    }
    
    int count(int tot) {
        int c=0;
        for(auto&i:m1)c+=mp[tot-i];
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */