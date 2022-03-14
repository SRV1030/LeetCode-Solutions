// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:unordered_map<int,vector<char>>mp;
    void util(vector<string>&res,string d,string t){
        if(d.length()==0)res.push_back(t);
        else{
            vector<char> ch=mp[d[0]-'0'];
            d.erase(d.begin());
            for(auto i:ch)util(res,d,t+i);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return{};
        vector<string>res;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        util(res,digits,"");
        return res;        
    }
};