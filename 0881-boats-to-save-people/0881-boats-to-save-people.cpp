class Solution {
public:
    int numRescueBoats(vector<int>& pep, int lmt) {
        sort(pep.begin(),pep.end());
        int s=0,c=0,i=0,j=pep.size()-1;
        while(i<=j){
            s=(i==j)?pep[i]:pep[j]+pep[i];
            if(s<=lmt){
                i++;
            }
            j--;
            c++;
        }
        return c;
    }
};