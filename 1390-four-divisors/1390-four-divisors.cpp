class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sm=0;
        for(auto&i:nums){
            int ld=0;
            for(int j=2;j*j<=i;++j){
                if(i%j==0){
                    if(ld==0)ld=j;
                    else {
                        ld=0;
                        break;
                    }
                }
            }
            if(ld && ld!=i/ld)sm+=(1+i+ld+i/ld);
        }
        return sm;
    }
};