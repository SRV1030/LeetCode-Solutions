class Solution {
public:
    int maximumGroups(vector<int>& g) {
        sort(begin(g),end(g));
        int ps=0,cs=0,pc=0,cc=0,ans=0;
        for(int i=0;i<size(g);++i){
            cs+=g[i];
            cc++;
            if(cs>ps && cc>pc){
                ++ans;
                ps=cs;
                pc=cc;
                cs=cc=0;
            }
        }
        return ans;
    }
};