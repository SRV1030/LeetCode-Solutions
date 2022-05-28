class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
        int r=g.size(),s=0;
        vector<int>z(r);
        for(int i=0;i<r;i++)
            for(int j=r-1;j>=0;j--){
                if(g[i][j])break;
                z[i]++;
            }
        for(int i=0;i<r;i++){
            int cur=i,req=r-1-i;
            if(z[cur]>=req)continue;
            while(cur<r && z[cur]<req)cur++;
            if(cur==r) return -1;
            s+=cur-i;
            while(cur>i){
                z[cur]=z[cur-1];
                --cur;
            }
        }
        return s;
    }
};