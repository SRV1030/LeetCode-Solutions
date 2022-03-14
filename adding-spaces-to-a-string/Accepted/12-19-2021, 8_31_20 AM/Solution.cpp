// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& v) {
        string ans="";
        int j=0;
        for(int i=0;i<s.length();i++){
            if(i==v[j]){
                ans+=' ';
                if(j!=v.size()-1)
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};