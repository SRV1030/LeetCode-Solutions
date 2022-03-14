// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution {
public:
    struct compare{
        bool operator()(const string a,const string b){
            if(a.size()==b.size())return a>b;
            return a.size()>b.size();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>, compare>pq;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};