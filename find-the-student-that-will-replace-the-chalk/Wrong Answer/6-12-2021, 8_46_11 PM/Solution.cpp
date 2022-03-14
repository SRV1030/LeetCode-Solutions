// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int s=accumulate(chalk.begin(),chalk.end(),0);
        return (k%s)%chalk.size();
        
    }
};