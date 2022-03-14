// https://leetcode.com/problems/keyboard-row

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="asdfghjkl",s2="zxcvbnm";
        int c1[26]={0},c2[26]={0};
        for(auto& i:s1)c1[i-'a']++;
        for(auto& i:s2)c2[i-'a']++;      
        vector<string> ans;
        for(auto& i:words){
            bool f1=false,f2=false,f3=false,el=false;
            for(auto& j:i){
                int x=j>='a'?j-'a':j-'A';
                if(c1[x])f1=true;
                else if(c2[x])f2=true;
                else f3=true;
                if(f1&&f2 || f2&&f3 || f1&&f3){
                    el=true;
                    break;
                }
            }
            if(!el)ans.push_back(i);
        }
        return ans;
    }
};