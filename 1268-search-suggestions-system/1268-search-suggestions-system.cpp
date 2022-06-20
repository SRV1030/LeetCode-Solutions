class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it=A.begin();
        sort(it,end(A));
        string cur;
        vector<vector<string>> ans;
        for(auto&i:searchWord){
            cur+=i;
            vector<string>t;
            it=lower_bound(it,end(A),cur);
            for(int i=0;i<3 && i+it!=end(A);++i){
                string s=*(it+i);
                if(s.find(cur))break;
                t.push_back(s);
            }
            ans.push_back(t);
        }
        return ans;
    }
};