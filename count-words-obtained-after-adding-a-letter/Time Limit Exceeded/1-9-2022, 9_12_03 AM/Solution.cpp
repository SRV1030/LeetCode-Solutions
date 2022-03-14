// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter

class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& targets) {
        int ans=0;
        map<vector<int>,int>m;
        for(auto s:start){
            vector<int>v(26);
            for(char c:s){
                v[c-'a']++;
            }
            m[v]++;
        }
        for(auto target:targets){
            vector<int>cTarget(26);
            for(char c:target){
                cTarget[c-'a']++;
            }
            for(int i=0;i<26;i++){
                if(cTarget[i]>0){
                    cTarget[i]=cTarget[i]-1;
                    if(m[cTarget]){
                        ans++;
                        break;
                    }
                    cTarget[i]=cTarget[i]+1;
                }
            }
        }
        return ans;
    }
};