class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        for(int i=0;i<fl.size();i++){
            if(fl[i]==1)i++;
            else if((i+1<fl.size() && fl[i+1]==0) || i==fl.size()-1){
                n--;
                i++;
            }
            if(n==0) break;
        }
        return n<=0;
    }
};