class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) {
        int ct=0,cf=0,ans=0,l=0,r=0,n=ak.size();
        while(r<n){
            if(ak[r++]=='T')ct++;
            else cf++;
            if(min(ct,cf)<=k) ans=max(ans,r-l);
            else{
                if(ak[l]=='T')ct--;
                else cf--;
                l++;
            }
        }
        return ans;
    }
};