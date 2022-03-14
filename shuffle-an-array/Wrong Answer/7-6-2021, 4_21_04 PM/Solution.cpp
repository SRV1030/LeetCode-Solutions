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
        int n=rand()%shuf.size();
        while(n--){
            int x=shuf[shuf.size()-1];
            shuf.pop_back();
            shuf.insert(shuf.begin(),x);            
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