class Solution {
public:
    long long hf;
    string getHalf(int q){
        int st=pow(10,hf-1);
        return to_string(st+q-1);
    }
    vector<long long> kthPalindrome(vector<int>& queries, int mxl) {
        vector<long long> ans;
        hf=mxl/2+(mxl%2?1:0);
        for(auto&q:queries){
            string gh= getHalf(q);
            string oh=mxl%2?gh.substr(0,gh.size()-1):gh;
            reverse(oh.begin(),oh.end());
            gh+=oh;
            if(gh.size()==mxl)ans.push_back(stoll(gh));
            else ans.push_back(-1);
        }
        return ans;
    }
};