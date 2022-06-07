class Solution {
public:
    unordered_set<string>st;
    int maxUniqueSplit(string s,int i=0) {
        if(i==size(s))return 0;
        int res=-1;
        for(int j=1;i+j<=size(s);++j){
            auto it=st.insert(s.substr(i,j));
            if(it.second){
                int nres=maxUniqueSplit(s,i+j);
                if(nres!=-1)res=max(res,nres+1);
                st.erase(s.substr(i,j));
            }
        }
        return res;
    }
};