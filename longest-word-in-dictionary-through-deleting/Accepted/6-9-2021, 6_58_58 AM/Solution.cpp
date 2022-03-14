// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

class Solution {
public:
    bool check(string i,string s){
        int n=i.size(),m=s.size();
        if(m<n) return false;
        int c=0,a=0,b=0;
        while(a<n && b<m){
            if(i[a]==s[b]){
                c++;
                a++;
                b++;
            }
            else b++;            
        }
        return c==n;
    }
    string findLongestWord(string s, vector<string>& dict) {
        vector<string> ans;
        for(auto i:dict)
            if(check(i,s)) ans.push_back(i);
        if(ans.size()==1)return ans[0];
        else if(ans.size()==0)return "";
        sort(ans.begin(),ans.end());        
        string res="";
        for(auto i:ans)
            if(i.length()>res.length())res=i;
        return res;
        
        
    }
};