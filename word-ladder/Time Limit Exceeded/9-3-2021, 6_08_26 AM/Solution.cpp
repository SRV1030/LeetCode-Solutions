// https://leetcode.com/problems/word-ladder

class Solution {
public:
    bool isCon(string a,string b){
        int c=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])
                c++;
            if(c>=2)
                return 0;
        }
        return c==0 ? 0 : 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {              
        wordList.insert(wordList.begin(),beginWord);  
        auto e=find(wordList.begin(),wordList.end(),endWord);
        if(e==wordList.end()) return 0;
        int n=wordList.size(),end=e-wordList.begin();
        vector<vector<int>>g(n);
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        queue<int>q;
        q.push(0);
        for(int i=0;i<n-1;i++)
            for(int j=1;j<n;j++)
                if(isCon(wordList[i],wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        while(!q.empty()){
            int src=q.front();
            q.pop();
            for(auto& i:g[src])
                if(dis[src]+1<dis[i]){
                    dis[i]=dis[src]+1;
                    q.push(i);
                }
        }
        return dis[end]==INT_MAX?0:dis[end]+1;
    }
};