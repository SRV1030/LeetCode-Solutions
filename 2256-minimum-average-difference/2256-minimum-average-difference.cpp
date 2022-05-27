class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long>p(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++)p[i]=nums[i]+p[i-1];
        int mnv=INT_MAX,ind=-1;
        for(int i=0;i<nums.size();i++){
            long long d=p[i]/(i+1)-(i==(nums.size()-1)?0:(p[nums.size()-1]-p[i])/(nums.size()-i-1));
            // cout<<abs(d)<<" ";
            d=abs(d);
            if(d<mnv){
                mnv=d;
                ind=i;
            }
        }
        return ind;
    }
};