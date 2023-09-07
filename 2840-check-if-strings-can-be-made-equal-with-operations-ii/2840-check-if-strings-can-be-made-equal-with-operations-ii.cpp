class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> t1(26),t2(26),t3(26),t4(26);
        for(int i=0;i<size(s1);++i){
            if(i&1){
                ++t1[s1[i]-'a'];
                ++t3[s2[i]-'a'];
            }
            else{
                ++t2[s1[i]-'a'];
                ++t4[s2[i]-'a'];
            }
        }
        return (t1==t3) && (t2==t4);
    }
};