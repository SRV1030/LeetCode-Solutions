// https://leetcode.com/problems/word-ladder

class Solution {
public:
    bool fun(string x,string y){
        int c=0;
        for(int i=0;i<x.length();i++){
            if(x[i]!=y[i]) c++;
        }
        if(c==1) return true;
        else return false;
    }
    int ladderLength(string begin, string end, vector<string>& s1) {
        int flag=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==end) flag=1;
        }
        if(flag==0) return 0;
        vector<string>s;
        s.push_back(begin);
        for(int i=0;i<s1.size();i++){
            s.push_back(s1[i]);
        }
        
        int n=s.size();
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(fun(s[i],s[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int e;
        for(int i=0;i<n;i++){
            if(s[i]==end){
                e=i;
                break;
            }
        }
        queue<int>q;
        q.push(0);
        vector<int>arr(n,INT_MAX);
        arr[0]=0;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            for(auto x:adj[num]){
                if(arr[num]+1<arr[x]) {arr[x]=arr[num]+1; q.push(x);}
            }
        }
        if(arr[e]==INT_MAX) return 0; 
        else return arr[e]+1;
    }
};