class Solution {
public:
    vector<long long> maximumEvenSplit(long long sum) {
        vector<long long> ans;
        for(long long cur=2;sum>0 && sum%2==0;cur+=2){
            if(sum-cur<cur+2)ans.push_back(sum);
            else ans.push_back(cur);
            sum-=ans.back();
        }
        return ans;
    }
};