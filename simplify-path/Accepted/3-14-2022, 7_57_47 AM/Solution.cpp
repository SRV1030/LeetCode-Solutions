// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        string res,temp;
        vector<string>st;
        stringstream str(path);
        while(getline(str,temp,'/')){
            if(temp=="" || temp==".") continue;
            if(temp!="..")st.push_back(temp);
            else if(!st.empty()) st.pop_back();
        }
        for(auto&s:st)res+="/"+s;
        return res.empty()?"/":res;
    }
};