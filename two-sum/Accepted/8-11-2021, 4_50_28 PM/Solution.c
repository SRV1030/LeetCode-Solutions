// https://leetcode.com/problems/two-sum



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(2 * (sizeof(int)));
    *returnSize = 2;

    
    for(int i=0; i<numsSize; i++) {
        
        for(int j=0; j<numsSize; j++) {
            
            if (j == i) continue;
            
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                goto EXIT_LOOP;
            }
        }
    }
EXIT_LOOP:
    
    return ret;
}