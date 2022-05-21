class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        sort(t.begin(),t.end());
        int n=t.size(),s=0,e=0,ans=0,area=0;
        for(;e<n && s<n;){
            if(t[s][0]+len>t[e][1]){
                area+=t[e][1]-t[e][0]+1;
                ans=max(ans,area);   
                ++e;
            }
            else{
                ans=max(ans,area+max(0,t[s][0]+len-t[e][0]));
                area-=(t[s][1]-t[s][0]+1);
                ++s;
            }
        }
        return ans;        
    }
};