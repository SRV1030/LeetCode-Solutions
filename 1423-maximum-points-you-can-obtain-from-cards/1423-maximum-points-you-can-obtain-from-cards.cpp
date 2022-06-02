class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=size(cp),mx=0;
        for(int i=0;i<k;++i)mx+=cp[i];
        if(k==n) return mx;
        int i=k-1,j=n-1,sm=mx;
        while(i>=0){
            sm+=(cp[j--]-cp[i--]);
            mx=max(mx,sm);
        }
        return mx;
    }
};