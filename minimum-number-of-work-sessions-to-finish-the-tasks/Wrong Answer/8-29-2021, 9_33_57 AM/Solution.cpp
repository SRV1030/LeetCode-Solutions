// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    int minSessions(vector<int>& tasks, int st) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end());
        int s=1,sum=0;
        for(auto& i:tasks){
            sum+=i;
            if(sum<=st)continue;
            else s++;
        }
        return s;
    }
};