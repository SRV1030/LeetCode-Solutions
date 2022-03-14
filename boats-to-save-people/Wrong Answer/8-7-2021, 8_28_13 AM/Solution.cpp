// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& pep, int lmt) {
        sort(pep.begin(),pep.end());
        int s=0,c=0;
        for(int i=0;i<pep.size();i++){
            s+=pep[i];
            if(s>=lmt){
                c++;
                if(s>lmt)i--;
                s=0;
            }
        }
        return c;
    }
};