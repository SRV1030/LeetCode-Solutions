class Solution {
public:
    int minNumberOfHours(int ie, int ex, vector<int>& energy, vector<int>& exp) {
        int s=0,c=0;
        for(int i=0;i<size(energy);++i){
            s+=energy[i];
            if(exp[i]>=ex){
                int t=exp[i]-ex+1;
                c+=t;
                ex+=t+exp[i];
            }
            else  ex+=exp[i];
        }
        return s>=ie?s-ie+1+c:c;
    }
};