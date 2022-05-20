class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            string t1=words[i-1],t2=words[i];
            sort(t1.begin(),t1.end());
            sort(t2.begin(),t2.end());
            while(t1==t2){
                i++;
                if(i>=words.size())break;
                t2=words[i];
                sort(t2.begin(),t2.end());
            }
            if(i>=words.size())break;
            ans.push_back(words[i]);
        }
        return ans;
    }
};