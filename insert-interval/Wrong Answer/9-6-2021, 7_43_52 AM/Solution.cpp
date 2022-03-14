// https://leetcode.com/problems/insert-interval

class Solution {
public: 
    int binarysearch(vector<vector<int>> in,int k){
        int l=0,r=in.size()-1,res=l;
        while(l<=r){
            int m=l+(r-l)/2;
            if(in[l][0]<=k){
                res=m;l=m+1;
            }
            else r=m-1;
        }
        return res;
    }   
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        if(in.empty()){
            in.push_back(ni);
            return in;
        }
        int i=binarysearch(in,ni[0]);
        if(i==0)i=in[0][0]<ni[0]?1:0;
        in.insert(in.begin()+i,ni);
        vector<vector<int>> ans;
        ans.push_back(in[0]);
        for(int i=1;i<in.size();i++){
            if(in[i][0]<=ans.back()[1])ans.back()[1]=max(ans.back()[1],in[i][1]);
            else ans.push_back(in[i]);
        }
        return ans;
    }
};