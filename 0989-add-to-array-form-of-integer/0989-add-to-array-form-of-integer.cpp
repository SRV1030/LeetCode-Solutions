class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n=size(num);
        while(--n>=0 || k){
            if(n>=0)k+=num[n];
            ans.push_back(k%10);
            k/=10;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};