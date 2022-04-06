class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rect) {
        int mx=0,c=0;
        for(auto&i:rect){
            int l=min(i[0],i[1]);
            if(l==mx)c++;
            else if(l>mx){
                mx=l;
                c=1;
            }
        }
        return c;
    }
};