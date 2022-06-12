class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = -1;
        int max_sum = 0;
        int sum = 0;
        
        array<int, 100001> prefix_sums = {};
        array<int, 10001> idxs;
        fill(begin(idxs), end(idxs), -1);
        
        for (int cur = 0; cur < nums.size(); ++cur) {            
            prefix_sums[cur] = nums[cur] + (cur > 0 ? prefix_sums[cur - 1] :0);
            if (idxs[nums[cur]] != -1) {
                left = max(left, idxs[nums[cur]] );
//                cout << nums[cur] << " was already seeen\n";
            }

            idxs[nums[cur]] = cur;

            sum =  prefix_sums[cur] - (left != -1 ? prefix_sums[left]   :0);
            max_sum = max(max_sum, sum);
            
        }
        
        return max_sum;
    }
};