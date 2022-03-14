// https://leetcode.com/problems/remove-comments

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string s="";
        for(auto& i:source){
            s+=i;
            s+='$';
        }
        vector<string> ans;
        string x="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='$'){
                if(x!="")ans.push_back(x);
                x="";
            }
            if(s[i]=='/'){
                if(s[i+1]=='/'){
                   size_t z= s.find("$",i+2);
                    i=z-1;
                }
                else if(s[i+1]=='*'){
                   size_t z= s.find("*/",i+2);
                    i=z+1; 
                }
                else if(s[i] != '$')
                        x += s[i];
            }
            else if(s[i] != '$') x+=s[i];
        }
        return ans;
    }
};