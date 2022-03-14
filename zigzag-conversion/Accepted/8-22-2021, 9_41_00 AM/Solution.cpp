// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int nR) {
        if(nR==1)return s;
        map<int,string>mp;
        int cur=0,dir=1;
        for(auto& i:s){
            cur+=dir;
            mp[cur].push_back(i);
            if(cur==1)dir=1;
            else if(cur==nR)dir=-1;
        }        
        string res="";
        for(auto& i:mp)res+=i.second;
        return res;
    }
};