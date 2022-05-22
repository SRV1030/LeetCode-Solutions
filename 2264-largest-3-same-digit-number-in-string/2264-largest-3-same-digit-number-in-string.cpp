class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i=0;i<num.size()-2;i++)
            if(num[i]==num[i+1] && num[i+1]==num[i+2]) ans=max(ans,num.substr(i,3));
        return ans;
    }
};