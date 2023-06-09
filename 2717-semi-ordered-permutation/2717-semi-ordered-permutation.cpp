class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int  n=size(nums),i=find(begin(nums),end(nums),1)-begin(nums),j=find(begin(nums),end(nums),n)-begin(nums);
        return n-1-j+i-(i>j);
    }
};