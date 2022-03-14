// https://leetcode.com/problems/word-ladder

class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {   
        auto e=find(wordList.begin(),wordList.end(),endWord);
        if(e==wordList.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        set<string>st(wordList.begin(),wordList.end());
        int ans=0;
        while(!q.empty()){            
            ans++;
            int sz=q.size();
            while(sz--){
                string fr=q.front();
                q.pop();
                for(int i=0;i<fr.size();i++){
                    char ch=fr[i];
                    for(char c='a';c<='z';c++){
                        fr[i]=c;
                        if(fr==endWord)return ans+1;
                        if(!st.count(fr)) continue;
                        st.erase(fr);
                        q.push(fr);
                    }
                    fr[i]=ch;
                }
            }           
        }
        return 0;
    }
};