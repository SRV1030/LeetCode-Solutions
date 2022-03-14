// https://leetcode.com/problems/time-needed-to-buy-tickets

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=tickets.size()*tickets[k];
        for(auto& i:tickets)
            if(i<tickets[k])ans-=(tickets[k]-i);
        return ans;
        
    }
};