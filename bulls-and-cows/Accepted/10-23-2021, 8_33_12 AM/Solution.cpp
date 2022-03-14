// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>v(10),xt;
        for(auto&i:secret)v[i-'0']++;
        int a=0,b=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                a++;
                --v[secret[i]-'0'];
            }
            else xt.push_back(i);
        }
        for(auto& i:xt){
            if(v[guess[i]-'0']>0){
                b++;
                --v[guess[i]-'0'];
            }
        }
        string ans=to_string(a)+'A'+to_string(b)+'B';
        return ans;
    }
};