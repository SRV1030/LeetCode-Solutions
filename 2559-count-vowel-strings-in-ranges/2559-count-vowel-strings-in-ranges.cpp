class Solution {
public:
    bool isVowel(char i){
        return i=='a'||i=='e'||i=='o'||i=='i'||i=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pre(size(words)+1,0),ans;
        int ind=0;
        for(auto&i:words){
            if(isVowel(i[0])&&isVowel(i[size(i)-1]))pre[ind+1]=pre[ind]+1;
            else pre[ind+1]=pre[ind];
            ++ind;
        }
        for(auto&i:queries)ans.push_back(pre[i[1]+1]-pre[i[0]]);
        return ans;
    }
};