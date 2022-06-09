class Solution {
public:
    int minOperationsMaxProfit(vector<int>& c, int b, int r) {
        int wt=0,ind=-1,mx=0,n=size(c),prof=0;
        for(int i=0;i<n||wt>0;++i){
            if(i<n)wt+=c[i];
            int go=min(4,wt);
            prof+=go*b-r;
            wt-=go;
            if(mx<prof){
                mx=prof;
                ind=i+1;
            }            
        }
        return ind;        
    }
};