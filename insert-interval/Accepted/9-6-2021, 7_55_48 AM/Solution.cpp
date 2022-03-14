// https://leetcode.com/problems/insert-interval

class Solution {
public: 
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        if(in.empty()){
            in.push_back(ni);
            return in;
        }
        int i=0;
        while(i<in.size() &&  in[i][0]<=ni[0] )i++;
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