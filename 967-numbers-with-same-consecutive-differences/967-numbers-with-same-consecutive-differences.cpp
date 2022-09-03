class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> q={1,2,3,4,5,6,7,8,9};
        for(int i=1;i<n;++i){
            vector<int>nq;
            for(auto&e:q){
                int t=e%10;
                if(t+k<10)nq.push_back(e*10+t+k);
                if(k && t-k>=0)nq.push_back(e*10+t-k);
            }
            q=nq;
        }
        return q;
    }
};