// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> g={'A','C','G','T'};
        unordered_set<string>b(bank.begin(),bank.end());
        queue<string>q;
        q.push(start);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string cur=q.front();
                q.pop();
                if(cur==end) return ans;
                b.erase(cur);
                for(int i=0;i<8;i++){
                    char c=cur[i];
                    for(int j=0;j<4;j++){
                        cur[i]=g[j];
                        if(b.find(cur)!=b.end())q.push(cur);
                    }
                    cur[i]=c;
                }                    
            }
            ans++;
        }
        return -1;
    }
};