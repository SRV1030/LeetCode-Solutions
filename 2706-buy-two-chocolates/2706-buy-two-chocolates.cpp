class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn=INT_MAX,smn=INT_MAX;
        for(auto&i:prices){
            if(i<mn){
                smn=mn;
                mn=i;
            }
            else if(i<smn)smn=i;
        }
        int v=mn+smn;
        return v<=money?money-v:money;
    }
};