// https://leetcode.com/problems/counting-bits



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *a;
    a=malloc(sizeof(int)*(n+1));
    a[0]=0;
    for(int i=1;i<n+1;i++)a[i]=i%2?1+a[i/2]:a[i/2];
    *returnSize =n+1;
    return a;
}