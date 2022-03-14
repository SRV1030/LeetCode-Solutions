// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
       vector<int>lis(obstacles.size());
        for(int i=0;i<obstacles.size();i++){
            lis[i]=1;
            for(int j=0;j<i;j++)
                if(obstacles[j]<=obstacles[i] && lis[i]<lis[j]+1)lis[i]=lis[j]+1;
        }
        return lis;
    }
};