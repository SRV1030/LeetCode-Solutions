class Solution {
public:
    int dp[501][501][2] = {};
    int maxDotProduct(vector<int>& n1, vector<int>& n2,int p1=0,int p2=0,bool emp=true) {
        if(p1>=size(n1) || p2>=size(n2)) return emp?-1000000:0;
        if(!dp[p1][p2][emp])dp[p1][p2][emp]=1+max({maxDotProduct(n1,n2,p1+1,p2,emp),maxDotProduct(n1,n2,p1,p2+1,emp),
                                                  maxDotProduct(n1,n2,p1+1,p2+1,false)+n1[p1]*n2[p2]});
        return dp[p1][p2][emp]-1;         
    }
};