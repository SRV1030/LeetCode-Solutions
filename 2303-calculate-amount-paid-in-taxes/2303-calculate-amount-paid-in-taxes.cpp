class Solution {
public:
    double calculateTax(vector<vector<int>>& br, int inc) {
        double ans=(min(br[0][0],inc)*br[0][1])/100.0;
        inc-=br[0][0];
        for(int i=1; inc>=0 && i<size(br);++i){
            int am=min((br[i][0]-br[i-1][0]),inc);
            inc-=am;
            ans+=(am*br[i][1])/100.0;
        }
        return ans;
    }
};