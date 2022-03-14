// https://leetcode.com/problems/count-common-words-with-one-occurrence

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>mp,mp1;
        for(auto&i:words1)mp[i]++;
        int c=0;
        for(auto&j:words2){
            if(mp.count(j)){
                if(mp[j]>=0)  mp[j]=(-1)*mp[j]-1;
                else mp[j]--;
            }
        }
            
        for(auto&[k,v]:mp)if(v==-2)c++;    
        return c;
    }
};