class Solution {
public:
int minMoves(vector<int> &ar,int k){
    int n=ar.size(),ans=n;
    vector<int> moves(2*k+2,0);
    for(int i=0;i<n/2;i++){
        int mn=min(ar[i],ar[n-1-i]),mx=max(ar[i],ar[n-1-i]);
        moves[mn+1]++,moves[mx+k+1]--;                      //  to make the sum of ar[i]+ar[n-1-i] in the range [mn+1,mx+k] we need to do 1 changes
        moves[mn+mx]--,moves[mn+mx+1]++;                    //  to make the sum of ar[i]+ar[n-1-i] in the range [mn+mx,mn+mx] we need to do 0 changes
        moves[mx+k+1]+=2,moves[2*k+1]-=2;                   //  to make the sum of ar[i]+ar[n-1-i] in the range [mx+k+1,2*k] we need to do 2 changes
        moves[2]+=2,moves[mn+1]-=2;                         //  to make the sum of ar[i]+ar[n-1-i] in the range [2,mn] we need to do 2 changes
    }
    for(int i=2;i<=2*k;i++) moves[i]+=moves[i-1],ans=min(ans,moves[i]);
    return ans;
}
};