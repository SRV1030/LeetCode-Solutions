class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegrees(numCourses);
        
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            ++inDegrees[prereq[0]];
        }
        
        queue<int> q;
        for (int i = 0; i < inDegrees.size(); ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++count;
            for (const auto& n : graph[cur]) {
                if (--inDegrees[n] == 0) {
                    q.push(n);
                }
            }
        }
        
        return count == numCourses;
    }
};