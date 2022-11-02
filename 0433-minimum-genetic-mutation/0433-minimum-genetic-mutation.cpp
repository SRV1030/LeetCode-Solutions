class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string s="ACGT";
        unordered_set<string>b(bank.begin(),bank.end());
        queue<string>q;
        q.push(start);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string x=q.front();
                q.pop();
                if(x==end) return lvl;
                b.erase(x);
                for(int i=0;i<8;i++){
                    char c=x[i];
                    for(int j=0;j<4;j++){
                        x[i]=s[j];
                        if(b.count(x)) q.push(x);
                    }
                    x[i]=c;
                }
            }            
             lvl++;
        }
        return -1;
    }
};