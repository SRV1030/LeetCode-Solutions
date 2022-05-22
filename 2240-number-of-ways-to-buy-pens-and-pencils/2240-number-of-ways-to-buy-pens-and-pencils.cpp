class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(total<0) return 0;
        return 1+total/cost2+waysToBuyPensPencils(total-cost1,cost1,cost2);
    }
};