class Solution {
public:
    int partitionString(string s) {
        set<char>st,ste;
        int c=1;
        for(auto&i:s){
            if(!st.insert(i).second){
                st=ste;
                st.insert(i);
                ++c;
            }
        }
        return c;
    }
};