class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for(int i=0;i<size(s);++i){
            while(indices[i]!=i){
                swap(s[i],s[indices[i]]);
                swap(indices[i],indices[indices[i]]);
            }
        }
        return s;
    }
};