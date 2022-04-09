class Solution {
public:
    vector<bool> canEat(vector<int>& cC, vector<vector<int>>& queries) {
        int n=cC.size();
        vector<bool>ans;
        vector<long>ps(n);
        ps[0]=cC[0];
        for(int i=1;i<n;i++)ps[i]+=ps[i-1]+cC[i];
        for(auto&q:queries){
            long t=q[0],d=q[1],c=q[2];
            ans.push_back((d+1)*c>(t==0?0:ps[t-1]) && d+1<=ps[t]);
        }
        return ans;
    }
};