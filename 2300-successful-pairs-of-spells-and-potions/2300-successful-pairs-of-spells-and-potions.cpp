class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& ps, long long sc) {
        sort(begin(ps),end(ps));
        vector<int>ans;
        for(auto&i:sp){
            int r=-1,l=0,h=size(ps)-1;
            while(l<=h){
                int m=(l+h)/2;
                if((long long )i*ps[m]>=sc){
                    r=m;
                    h=m-1;
                }
                else l=m+1;
            }
            if(r>=0)ans.push_back(size(ps)-r);
            else ans.push_back(0);
        }
        return ans;
    }
};