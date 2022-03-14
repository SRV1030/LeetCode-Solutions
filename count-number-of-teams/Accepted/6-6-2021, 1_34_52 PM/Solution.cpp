// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rate) {
        int ans=0;
        for(int i=1;i< rate.size();i++){
            int lmn=0,lmx=0,rmn=0,rmx=0;
            for(int j=i-1;j>=0;j--){
                if(rate[j]>rate[i])lmx++;
                else lmn++;
            }
            for(int j=i+1;j< rate.size();j++){
                if(rate[j]>rate[i])rmx++;
                else rmn++;
            }
             ans+= lmx*rmn+lmn*rmx;
        }
       return ans;
    }
    
};