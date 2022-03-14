// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>pop(101);
        for(auto&i:logs){
            pop[i[0]-1950]++;
            pop[i[1]-1950]--;
        }
        for(int i=1;i<pop.size();i++)pop[i]+=pop[i-1];
        int mx=0,mxyr=0;
        for(int i=0;i<pop.size();i++){
            if(pop[i]>mx){
                mx=pop[i];
                mxyr=i+1950;
            }
        }
        return mxyr;
    }
};