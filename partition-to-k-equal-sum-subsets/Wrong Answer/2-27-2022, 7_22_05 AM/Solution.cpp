// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        int t = (1<<n); //2^n
        sort(nums.begin(),nums.end(),greater<int>());
                
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%k!=0){
            return false;
        }
        
        sum = sum/k;
        int cnt=0;
        int taken=0;
        
        for(int m=0;m<t;m++){
            int x = 0;            
            if(!(m&taken)){ // check iff elemts chosen or not.
                for(int i=0;i<n;i++){
                    if(m&(1<<i)){
                        x+=nums[i]; 
                        
                    }
                }
                if(x==sum){                
                    taken = m;
                    cnt++;                    
                }
            }
        }      
        return cnt>=k ;        
    }
};


// Key Points :

// We can chose a element only once.
// We must select every element of the given set.
// Approach :

// We can check every subset for the sum = sum/k.
// If a subset has the req sum, we increase the count.
// If the total count is greater than equal to k, we return true.
// What have I done

// Used BIT-MASKING to check for each subset, if it contains sum= total_sum/k;
// Since we cannot chose a already choosen element once, we use a var taken to keep track of the elements choosen.
// how does var 'taken' work
// Assume we have a set [2,3,8,7,10].
// suppose we have choosen the 2nd and 4th element [3,7] (from the left). Taken become decimal of 01010.
// Now when we check for subset containing 1st,2nd and 4th element i.e m=11010 (assume). Then AND of mask 'm' and taken is !=0, hence we dont consider this subset.

// NOTE: we need to sort the nums array in decreasing order, as bitmasking checks from right to left, and we need to make subsets of smaller elements as possible(no concreate proof why so)

// Time Complexity : O((2^n) * n).

