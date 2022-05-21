class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string v=to_string(num);
        int c=0,n=v.size();
        for(int i=0;i<n-k+1;++i){
            int t=stoi(v.substr(i,k));
            if(!t)continue;
            if(num%t==0)c++;
        }
        return c;
    }
};