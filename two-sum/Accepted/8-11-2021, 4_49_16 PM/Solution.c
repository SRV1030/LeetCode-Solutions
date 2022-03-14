// https://leetcode.com/problems/two-sum



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;   //need to give returnSize his lenght!
    int i = 0;
    int j = 1;
    int* array = (int*)malloc(2*sizeof(int));
    while(i < numsSize - 1 && numsSize > 1)
    {
        while(j < numsSize)
        {
            if(nums[i] + nums[j] == target && i != j)
            {
                array[0] = i;
                array[1] = j;
                return(array);
            }
            j++;
        }
        j = i + 1;
        i++;
    }
    return(0);
    
}