// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> v={-100000,100000};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int mx=INT_MIN,n=nums.size(),d=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i][0]>mx)mx=nums[i][0];
            pq.push({nums[i][0],i,0});
        }        
        while(!pq.empty()){
            vector<int>mn=pq.top();
            pq.pop();
            int td=mx-mn[0];
            if(td<d){
                d=td;
                v={mn[0],mx};
            }
            if(mn[2]+1<nums[mn[1]].size()){
                if(nums[mn[1]][mn[2]+1]>mx)mx=nums[mn[1]][mn[2]+1];
                pq.push({nums[mn[1]][mn[2]+1],mn[1],mn[2]+1});
            }
            else break;
        }
        return v;
    }
};