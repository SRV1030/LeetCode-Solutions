// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

class Solution {
public:
    
    int solve(vector<int>& prices, int &fee,bool own,int i){
        if(i==prices.size()) return 0;
        if(own){
            int o1=prices[i]+solve(prices,fee,!own,i+1);
            int o2=solve(prices,fee,own,i+1);
            return max(o1,o2);
        }
        else{
           int o1=-(prices[i]+fee)+solve(prices,fee,1,i+1);
           int o2=solve(prices,fee,0,i+1);
           return max(o1,o2); 
        }
        return 0;
    }
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)return 0;
        return solve(prices,fee,false,0);
    }
};