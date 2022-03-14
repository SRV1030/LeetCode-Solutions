// https://leetcode.com/problems/plates-between-candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> vec, ans;
        for (int i = 0; i < s.length(); i++) 
            if (s[i] == '|')  vec.push_back(i);
        
        for(auto& i:queries){
            int p;
            auto itl=lower_bound(vec.begin(),vec.end(),i[0]);
            auto ith=lower_bound(vec.begin(),vec.end(),i[1]);
            if(itl==vec.end() || *itl>=i[1])p=0;
            else if(ith==vec.end() || *ith > i[1]){
                ith=prev(ith);
                p=*ith-*itl-(ith-itl);
            }
            else  p=*ith-*itl-(ith-itl);
            ans.push_back(p);
        }
        return ans;
        
    }
};