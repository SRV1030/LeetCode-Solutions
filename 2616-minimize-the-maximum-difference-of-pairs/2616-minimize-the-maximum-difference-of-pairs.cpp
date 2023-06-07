class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int l=0,r=nums[size(nums)-1]-nums[0];
        while(l<r){
            int m=(l+r)/2,c=0;
            for(int i=0;i<size(nums)-1;++i){
                int d=nums[i+1]-nums[i];
                if(m>=d){
                    ++c;
                    ++i;
                }
            }
            if(c>=p)r=m;
            else l=m+1;
        }
        return l;
    }
};