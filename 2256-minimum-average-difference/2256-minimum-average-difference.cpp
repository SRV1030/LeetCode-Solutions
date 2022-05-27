// class Solution {
// public:
//     int minimumAverageDifference(vector<int>& nums) {
//         vector<long long>p(nums.size());
//         p[0]=nums[0];
//         for(int i=1;i<nums.size();i++)p[i]=nums[i]+p[i-1];
//         int mnv=INT_MAX,ind=-1;
//         for(int i=0;i<nums.size();i++){
//             long long d=p[i]/(i+1)-(i==(nums.size()-1)?0:(p[nums.size()-1]-p[i])/(nums.size()-i-1));
//             d=abs(d);
//             if(d<mnv){
//                 mnv=d;
//                 ind=i;
//             }
//         }
//         return ind;
//     }
// };

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long l=0,r=0,n=size(nums),mn=INT_MAX,ind=-1;
        for(auto&i:nums)r+=i;
        for(int i=0;i<n;i++){
            l+=nums[i];
            r-=nums[i];
            long long fs=l/(i+1),bs=(i==n-1)?0:r/(n-i-1),d=abs(fs-bs);;
            if(d<mn){
                mn=d;
                ind=i;
            }
        }
        return ind;
    }
};