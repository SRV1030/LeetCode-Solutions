class Solution {
public:
    int candy(vector<int>& r) {
        vector<int>cd(size(r),1);
        for(int i=1;i<size(r);++i)if(r[i]>r[i-1])cd[i]=cd[i-1]+1;
        int c=cd[size(r)-1];
        for(int i=size(r)-2;i>=0;--i){
            if(r[i]>r[i+1])cd[i]=max(cd[i],cd[i+1]+1);
            c+=cd[i];
        }
        return c;        
    }
};