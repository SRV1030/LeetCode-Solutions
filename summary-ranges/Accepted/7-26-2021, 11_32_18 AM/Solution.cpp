// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {        
        vector<string> ans;
        if(nums.size()==0) return ans;
        string t=to_string(nums[0]);
        int c=0;
        for(int i=1;i<nums.size();i++){
            if((long long int)nums[i]-(long long int)nums[i-1]==0)continue;
            if((long long int)nums[i]-(long long int)nums[i-1]==1) c++;
            else{
                if(c>0){
                    t+="->";
                    t+=to_string(nums[i-1]);                    
                }
                c=0;
                ans.push_back(t);
                t=to_string(nums[i]);
            }
        }
        if(c>0){
            t+="->";
            t+=to_string(nums[nums.size()-1]);                    
        }
        ans.push_back(t);
        return ans;
    }
};