class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(auto&i:s){
            if(i!='*')ans+=i;
            else {
                if(!empty(ans))ans.pop_back();
            }
        }
        return ans;
    }
};