class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1,mx=-1;
        while(l<r){
            if(h[l]<=h[r]){
                mx=max(mx,(r-l)*h[l]);
                l++;
            }else{
                 mx=max(mx,(r-l)*h[r]);
                r--;
                
            }
        }
        return mx;
    }
};