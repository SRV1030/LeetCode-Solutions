// https://leetcode.com/problems/jump-game-vii

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        q.push(0);
        int r=0;
        int n=s.size();
        if(s[n-1]!='0') return false;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            if(cur==n-1) return true;
            for(int i=cur+minJump;i<=min(cur+maxJump,n-1);i++)
                if(s[i]=='0') q.push(i);
        }
        return false;
    }
};