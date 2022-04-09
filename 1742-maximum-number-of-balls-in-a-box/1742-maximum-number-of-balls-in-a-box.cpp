class Solution {
public:
    int countBalls(int lm, int hm) {
        int ans=0,v[46]={0};
        for(int i=lm;i<=hm;i++){
            int s=0,n=i;
            while(n){
                s+=n%10;
                n/=10;
            }    
            v[s]++;
            ans=max(ans,v[s]);
        }
        return ans;
    }
};