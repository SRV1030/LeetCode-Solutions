// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        int c=0;
        for(auto& i:num){
            while(!s.empty() && s.back()>i && c<k){
                s.pop_back();
                c++;
            }
            s+=i;           
        }
        s.resize(num.size()-k);
        string res="";
        bool leading=true;
        for(auto& i:s){
            if(leading && i=='0')continue;
            leading=false;
            res+=i;
        }
        return res.empty()?"0":res;
    }
};