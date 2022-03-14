// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>prf(numCourses),ans;
        vector<vector<int>>c(numCourses);
        for(auto&i:prerequisites){
            c[i[1]].push_back(i[0]);
            prf[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
            if(!prf[i]) q.push(i);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                for(auto& s:c[x]){
                    prf[s]--;
                    if(!prf[s])q.push(s);
                }
            }
        }
        return ans.size()==numCourses?ans:vector<int>();
    }
};