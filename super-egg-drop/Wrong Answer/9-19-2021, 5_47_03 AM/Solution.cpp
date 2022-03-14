// https://leetcode.com/problems/super-egg-drop

class Solution {
public: int t[101][10001];
    int sup(int e,int f){
        if(e==1 || f<=1) return f;
        if(t[e][f]!=1) return t[e][f];
        int i=1,j=f,mn=INT_MAX;
        while(i<=j){
            int m=i+(j-i)/2;
            int d=sup(e-1,m-1),u=sup(e,f-m);
            mn=min(mn,1+max(u,d));
            if(d<u)i=m+1;
            else j=m-1;
        }
        return t[e][f]=mn;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return sup(k,n);
    }
};