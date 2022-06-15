class Solution {
public:
    bool valid(vector<int>&bd,int m,int k,int mid){
        int adj=0;
        for(auto&i:bd){
            adj=i<=mid?adj+1:0;
            if(adj==k){
                --m;
                adj=0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bd, int m, int k) {
        if(m*k>size(bd))return -1;
        int l=1,h=1000000000;
        while(l<h){
            int mid=(l+h)/2;
            if(valid(bd,m,k,mid))h=mid;
            else l=mid+1;
        }
        return l;
    }
};