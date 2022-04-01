class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string>st;
        for(int i=0;i<w.size();i++){
            if(isdigit(w[i])){
                string s;
                while(isdigit(w[i]))s+=w[i++];
                int j=0;
                while(j<s.size()-1 && s[j]=='0')j++;                
                if(j<s.size())st.insert(s.substr(j));
            }            
        }
        return st.size();
    }
};