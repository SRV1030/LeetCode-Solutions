// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sg=0,sc=0,sum=0,ans=-1;
        for(int i=0;i<gas.size();i++){
            sg+=gas[i];
            sc+=cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0){
                sum=0;
                ans=i+1;
            }            
        }
        if(sg<sc) return -1;
         return ans;
    }
};