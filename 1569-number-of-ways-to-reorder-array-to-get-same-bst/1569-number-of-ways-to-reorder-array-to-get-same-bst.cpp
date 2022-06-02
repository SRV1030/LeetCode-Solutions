#define li long long int
class Solution {
public:
    int md=1e9+7;
    vector<vector<int>>c;
    int numOfWays(vector<int>& nums) {
        int n=size(nums);
        c.resize(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            c[i][0]=1;
            for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%md;
        }
        return f(nums)%md-1;
    }
    li f(vector<int>&nums){
        int n=size(nums);
        if(n<=1)return 1;
        vector<int>sm,gr;
        int root=nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]>root)gr.emplace_back(nums[i]);
            else sm.emplace_back(nums[i]);
        }
        return ((((f(sm)%md)*(f(gr)%md))%md)*(c[n-1][size(sm)]%md))%md;
    }
};