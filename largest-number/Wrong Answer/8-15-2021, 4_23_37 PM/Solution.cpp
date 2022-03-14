// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            string x=to_string(a),y=to_string(b);
            if(x[0]!=y[0])return x[0]>y[0];
            return stol(x+y)>stol(y+x);
        });
        string s="";
        for(auto& i:nums)s+=to_string(i);
        return s;
    }
};