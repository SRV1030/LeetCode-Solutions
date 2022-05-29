class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>nums;
        for(auto&i:words){
            bitset<32>bt;
            for(auto&j:i)bt[j-'a']=1;
            nums.push_back(bt.to_ulong());
        }
        unsigned long mx=0;
        for(int i=0;i<size(nums);++i)
            for(int j=i+1;j<size(nums);++j)
                if((nums[i]&nums[j])==0)mx=max(mx,size(words[i])*size(words[j]));
        return mx;
            
    }
};