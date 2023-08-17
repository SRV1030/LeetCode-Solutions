class Solution {
public:
    string finalString(string s) {
        string ans;
        for(auto&i:s){
            if(i=='i')reverse(begin(ans),end(ans));
            else ans+=i;
        }
        return ans;        
    }
};