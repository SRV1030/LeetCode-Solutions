class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> q={1,2,3,4,5,6,7,8,9};
        for(int i=1;i<n;++i){
            unordered_set<int>nq;
            for(auto&e:q){
                int t=e%10;
                if(t-k>=0)nq.insert(e*10+t-k);
                if(t+k<10)nq.insert(e*10+t+k);                
            }
            q=nq;
        }
        return vector<int>(begin(q),end(q));
    }
};