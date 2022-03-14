// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int buy = INT_MIN;
        int sell = 0;
        int prevsell = 0;
        
        for(int i = 0; i < n; i++)
        {
            
            buy = max(prevsell - prices[i], buy);
            prevsell = sell;
            sell = max(buy + prices[i], sell);
            
        }
        return sell;
    }
};