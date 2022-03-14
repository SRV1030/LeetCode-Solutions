// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0,cur=0;
        for(int i=0;i<prices.size();i++){
            if(i==0){
                cur++;
            }else{
                if(prices[i-1]-prices[i]==1){
                    cur++;
                }else{
                    ans+=((cur)*(cur+1))/2;
                    cur=1;
                    
                }
            }
        }
        ans+=((cur)*(cur+1))/2;
        return ans;
    }
};