// https://leetcode.com/problems/minimum-operations-to-convert-number

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int x=1000;
        queue<int>q;
        vector<int>st(10001);
        q.push(start);
        int steps=0;
        while(!q.empty()){
            int n=q.size(); 
            while(n--){
                int a=q.front();
                q.pop();
                if(a==goal)return steps;
                if(a<0 || a>1000 || st[a]) continue;
                st[a]++;
                for(auto&i:nums){
                    int f=a+i,s=a-i,t=a^i;
                    q.push(f);
                    q.push(s);
                    q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};