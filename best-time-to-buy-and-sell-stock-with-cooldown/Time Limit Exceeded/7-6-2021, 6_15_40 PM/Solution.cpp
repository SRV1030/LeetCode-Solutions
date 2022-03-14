// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
public:int t[5001];
    int solve(vector<int>& p,int ind,int stock){
        if(ind>=p.size()) return 0;
        int res=0;
        if(t[ind]!=-1) return t[ind];
        if(stock==-1){          
            res=solve(p,ind+1,stock);
            res=max(res,solve(p,ind+1,p[ind]));
           
        }else{
            res=solve(p,ind+1,stock);
            if(p[ind]>stock){
                res=max(res,p[ind]-stock+solve(p,ind+2,-1));
            }
        }
         return res;
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return solve(prices,0,-1);
    }
};