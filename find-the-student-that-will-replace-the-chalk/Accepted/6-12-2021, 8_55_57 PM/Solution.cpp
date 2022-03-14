// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int s=0;
        for(auto i: chalk)s+=i;
        k=k%s;
        int i;
        for(i=0;i<chalk.size();i++){
            if(k<chalk[i]) break;
            k-=chalk[i];
        }
        return i;
        
    }
};