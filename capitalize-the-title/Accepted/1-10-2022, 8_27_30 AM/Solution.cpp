// https://leetcode.com/problems/capitalize-the-title

class Solution {
public:
    string capitalizeTitle(string title) {
        string ans,word;
        stringstream str(title);
        while(str>>word){
            if(word.length()<=2){
                for(auto& i:word)i=tolower(i);
            }
            else{
                word[0]=toupper(word[0]);
                for(int i=1;i<word.size();i++)word[i]=tolower(word[i]);
            }
            ans+=word+" ";
        }
        ans.pop_back();
        return ans;
    }
};