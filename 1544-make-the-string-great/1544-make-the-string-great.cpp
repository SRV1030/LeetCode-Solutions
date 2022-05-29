class Solution {
public:
    string makeGood(string s) {
        string res;
        for(auto&i:s){
            if(!res.empty()){
                char c=res.back();
                if(c!=i && tolower(c)==tolower(i))res.pop_back();
                else res.push_back(i);
            }
            else res.push_back(i);
        }
        return res;
    }
};