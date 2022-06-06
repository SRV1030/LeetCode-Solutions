class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int i=0,c=1;
        for(int j=0;j<size(nums);++j){
            if(nums[j]-nums[i]>k){
                c++;
                i=j;
            }
        }
        return c;
    }
};