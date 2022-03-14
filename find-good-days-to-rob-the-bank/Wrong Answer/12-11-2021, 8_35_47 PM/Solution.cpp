// https://leetcode.com/problems/find-good-days-to-rob-the-bank

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>ans;
        int n=security.size();
        for(int i=time;i<n-time;i++){
            int j=i-1,k=i+1,f=0;
            while(j>=i-time && k<=i+time){
                if(security[i]>security[j] || security[i]>security[k]){
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