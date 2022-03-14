// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>ans;
        int i=0;
        while(n){
            int val=min(n,k);
            string now=s.substr(i,val);
            if(now.length()<k){
                now+=string(k-n,fill);
            }
            ans.push_back(now);
            n=n-min(n,k);
            i=i+k;
        }
        return ans;
    }
};