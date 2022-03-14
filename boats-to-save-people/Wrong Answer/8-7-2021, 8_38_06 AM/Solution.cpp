// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& pep, int lmt) {
        sort(pep.begin(),pep.end());
        int s=0,c=0,i=0,j=pep.size()-1;
        while(i<=j){
            if(pep[j]+pep[i]<=lmt){
                i++;
            }
            j--;
            c++;
            if(i==j)c++;
        }
        return c;
    }
};