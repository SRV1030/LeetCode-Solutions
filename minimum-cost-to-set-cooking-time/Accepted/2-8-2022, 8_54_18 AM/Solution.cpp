// https://leetcode.com/problems/minimum-cost-to-set-cooking-time

class Solution {
public:
    int fcost(int start,int mins,int sec,int moveCost, int pushCost){
        if(min(mins,sec)<0 || max(mins,sec)>99) return INT_MAX;
        string tg=to_string(mins*100+sec);
        char st=(char)(start+'0');
        int cost=0;
        for(auto&d:tg){
            cost+=pushCost+(d==st?0:moveCost);
            st=d;
        }
        return cost;
    }
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int mins= targetSeconds/60,sec=targetSeconds%60;
        return min(fcost(startAt,mins,sec,moveCost,pushCost),fcost(startAt,mins-1,sec+60,moveCost,pushCost));      
    }
};