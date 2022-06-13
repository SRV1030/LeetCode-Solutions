class Solution {
public:
    vector<int>v;
    int ans=INT_MAX;
    void solve(vector<int>& cks,int ind){
        if(ind==size(cks))ans=min(ans,*max_element(begin(v),end(v)));
        else{
            for(auto&i:v){
                i+=cks[ind];
                solve(cks,ind+1);
                i-=cks[ind];
            }
        }
    }
    int distributeCookies(vector<int>& cks, int k) {
        if(k==size(cks))return *max_element(begin(cks),end(cks));
        v.resize(k);
        solve(cks,0);
        return ans;
    }
};