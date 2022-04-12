class Solution {
public:
    int maxDepth(string s) {
        int mx=0,c=0;
        for(auto&i:s){
            if(i!='(' && i!=')') continue;
            if(i=='(') c++;
            else  c--;
            mx=max(mx,c);
        }
        return mx;
    }
};