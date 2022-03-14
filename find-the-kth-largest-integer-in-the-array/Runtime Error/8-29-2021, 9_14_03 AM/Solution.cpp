// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>>pq;
        for(auto i:nums){
            pq.push(stoi(i));
            if(pq.size()>k)pq.pop();
        }
        return to_string(pq.top());
    }
};