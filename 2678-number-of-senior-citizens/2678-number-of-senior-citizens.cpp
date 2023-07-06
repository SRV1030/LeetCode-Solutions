class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c=0;
        for(auto&i:details){
            string s;
            s+=i[11];
            s+=i[12];
            if(stoi(s)>60)++c;
        }
        return c;
    }
};