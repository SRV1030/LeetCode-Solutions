class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long bg) {
        int i=0,j=0;
        long s=0;
        multiset<int,greater<int>> mst;
        for(;j<size(ct);++j){
            mst.insert(ct[j]);
            s+=rc[j];
            long long c=*mst.begin()+(j-i+1)*s;
            if(c>bg){
                mst.erase(ct[i]);
                s-=rc[i++];
            }
        }
        return j-i;        
    }
};