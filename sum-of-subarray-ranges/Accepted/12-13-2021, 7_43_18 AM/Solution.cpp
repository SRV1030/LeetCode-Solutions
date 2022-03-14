// https://leetcode.com/problems/sum-of-subarray-ranges

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long int sum = 0;
        int n = nums.size();
    
        for (int i = 0; i < n; i++) {
            int mn = nums[i];
            int mx = nums[i];
        
            for (int j = i; j < n; j++) {

                if(nums[j]>mx)
                {
                    mx = nums[j];
                }
                if(nums[j]<mn)
                {
                    mn = nums[j];
                }
                sum = sum + (mx - mn);
			}
		}
		return sum; 
	   }
   };