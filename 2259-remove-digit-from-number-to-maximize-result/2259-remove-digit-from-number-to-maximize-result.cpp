class Solution {
public:
    string removeDigit(string n, char d) {
        int lo=-1;
        for(int i=0;i<n.size();i++){
            if(n[i]==d){
                if(i+1<n.size() && n[i]<n[i+1]){
                    n.erase(n.begin()+i);
                    return n;
                }else lo=i;
            }
        }
        n.erase(n.begin()+lo);
        return n;
    }
};