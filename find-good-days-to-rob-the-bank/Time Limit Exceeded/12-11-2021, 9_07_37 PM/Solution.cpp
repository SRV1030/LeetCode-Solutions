// https://leetcode.com/problems/find-good-days-to-rob-the-bank

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>ans;
        if(time==0) {
            for(int i=0;i<security.size();i++)ans.push_back(i);
            return ans;
        }
        int n=security.size();
        for(int i=time;i<n-time;i++){
            int j=i,k=i,f=0;
            while(j>=i-time+1 && k<=i+time-1){
                if(security[j]>security[j-1] || security[k]>security[k+1]){
                    f=1;
                    break;
                }
                j--;
                k++;
            }
            if(!f)ans.push_back(i);
        }
        return ans;
    }
};