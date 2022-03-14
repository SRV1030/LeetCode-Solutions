// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long int s=accumulate(chalk.begin(),chalk.end(),0);
        k=k%s;
        int i;
        for(i=0;i<chalk.size();i++){
            if(k<chalk[i]) break;
            k-=chalk[i];
        }
        return i;
        
    }
};