class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int ts) {
        sort(b.begin(),b.end(),[](vector<int>&a,vector<int>&b){return a[1]>b[1];});
        int c=0;
        for(auto&i:b){
            int mn=min(i[0],ts);
            ts-=mn;
            c+=mn*i[1];
            if(ts<=0) return c;
        }
        return c;
    }
};