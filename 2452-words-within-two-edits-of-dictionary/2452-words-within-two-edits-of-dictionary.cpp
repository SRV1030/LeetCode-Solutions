class Solution {
public:
    int hammingdis(string a,string b){
        int c=0;
        for(int i=0;i<size(a);++i){
            if(a[i]!=b[i])++c;
            if(c>=3) return c; 
        }
        return c;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto&i:queries)
            for(auto&j:dictionary)
                if(hammingdis(i,j)<=2){
                    ans.push_back(i);
                    break;
                }
        return ans;
    }
};