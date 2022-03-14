// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    bool isAnar(string s1,string s2){
        if(s1.size()!=s2.size()) return false; 
        int a[27]={0};
        for(int i=0;i<s1.size();i++){a[s1[i]-'a']++;a[s2[i]-'a']--;}
        for(int i=0;i<26;i++)if(a[i]!=0) return false;
        return true;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> temp;
        // int x=0;
        while(strs.size()>0){
            temp.push_back(strs[0]); 
            string s=strs[0];
            strs.erase(strs.begin());
            for(int j=0;j<strs.size() && strs.size()>0;j++){
                if(isAnar(s,strs[j])){
                     temp.push_back(strs[j]);           
                     strs.erase(strs.begin()+j);   
                     j--;
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }
};