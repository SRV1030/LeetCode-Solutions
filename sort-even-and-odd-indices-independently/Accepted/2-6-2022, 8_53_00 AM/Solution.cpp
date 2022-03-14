// https://leetcode.com/problems/sort-even-and-odd-indices-independently

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>a,b;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int n=0,k=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)nums[i]=a[n++];
            else nums[i]=b[k++];
        }
        return nums;
    }
};