// https://leetcode.com/problems/letter-case-permutation

class Solution {
public: vector<string> v;
    void perm(string i,string o){
        if(i.size()==0) v.push_back(o);
        else{
            if(isdigit(i[0])){
                o+=i[0];
                i.erase(i.begin());
                perm(i,o);
            }
            else{
                string o1=o;
                o+=tolower(i[0]);
                o1+=toupper(i[0]);
                i.erase(i.begin());
                perm(i,o);
                perm(i,o1);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        perm(s,"");
        return v;
    }
};