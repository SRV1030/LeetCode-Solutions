class Solution {
public:
    int maximumBags(vector<int>& cp, vector<int>& rs, int aR) {
        vector<int>v;
        for(int i=0;i<cp.size();i++)v.push_back(cp[i]-rs[i]);
        sort(v.begin(),v.end());
        int c=0;
        for(auto&i:v){
            if(aR>=i)c++;
            aR-=i;
            if(aR<=0) break;
        }
        return c;
    }
};