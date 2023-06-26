class Solution {
public:
    long long totalCost(vector<int>& ct, int k, int cd) {
        long long sm=0;
        priority_queue<int,vector<int>,greater<>>pqf,pqb;
        int i=0,j=size(ct)-1;
        for(;i<cd;++i)pqf.push(ct[i]);
        for(;i<j && j>=size(ct)-cd-1;--j)pqb.push(ct[j]);
        while(k--){
            int f=pqf.empty()?-1:pqf.top(),b=pqb.empty()?-1:pqb.top();
            if(f==b){
                sm+=max(f,0);
                pqf.pop();
            }
            else if(f<b){
                if(f==-1){
                    sm+=b;
                    pqb.pop();
                }else{
                    sm+=f;
                    pqf.pop();
                }
            }else{
                if(b==-1){
                    sm+=f;
                    pqf.pop();
                }else{
                    sm+=b;
                    pqb.pop();
                }
            }
            if(i<=j){
                if(size(pqf)<size(pqb))pqf.push(ct[i++]);
                else if(size(pqf)>size(pqb))pqb.push(ct[j--]);
            }
            // cout<<sm<<"\n";
        }
        return sm;
    }
};