class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream str(s);
        string w,ans;
        while(str>>w && k--) ans+=w+" "; 
        ans.pop_back();
        return ans;
    }
};