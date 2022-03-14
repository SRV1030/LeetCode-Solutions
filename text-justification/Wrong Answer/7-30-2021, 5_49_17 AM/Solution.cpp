// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size()==0) return {};
        int ls=words[0].size(),start=0;
        vector<string> ans;
        for(int i=1;i<words.size();i++){
            if(ls+1+words[i].size()<=maxWidth)ls+=1+words[i].size();
            else{
                ans.push_back(genWord(words,start,i,maxWidth,ls));
                start=i;
                ls=words[i].size();
            }
        }
        ans.push_back(genLastWord(words,start,maxWidth));
        return ans;
    }
    string genWord(vector<string>& words,int start,int end, int maxWidth,int ls){
        string ret=words[start];
        for(int i=start+1;i<end;i++){            
            int spaces=(maxWidth-ls)/(end-i);
            if((maxWidth-ls)%(end-start))spaces++;
            ls+=spaces;
            for(int j = 0;j<=spaces;j++)ret.push_back(' ');
            ret+=words[i];
        }
        while(ret.size()<maxWidth)ret.push_back(' ');
        return ret;
    }
    string genLastWord(vector<string>& words,int start,int maxWidth){
        string ret=words[start];
        for(int i=start+1;i<words.size();i++)ret+=" "+words[i];
        while(ret.size()<maxWidth)ret.push_back(' ');
        return ret;
    }
};