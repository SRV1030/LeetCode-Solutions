// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:vector<int> og,shuf;
    Solution(vector<int>& nums) {
        og=nums;
        shuf=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuf=og;
        return shuf;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n=shuf.size();
        int ls=n;
        for(int i=n-1;i>=0;i--){
            int x=rand()%ls;
            swap(shuf[i],shuf[x]);
            ls--;
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */