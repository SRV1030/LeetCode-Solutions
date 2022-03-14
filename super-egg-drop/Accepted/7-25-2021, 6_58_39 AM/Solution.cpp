// https://leetcode.com/problems/super-egg-drop

class Solution {
public:
    int t[101][10001];   
    int sup(int k,int n){        
        if(k==1 || n<=1) return n;
        if(t[k][n]!=-1) return t[k][n];
        int i=1,j=n,mn=INT_MAX;
        while(i<=j){
            int m=i+(j-i)/2;
            int l=sup(k-1,m-1);
            int r=sup(k,n-m);
            mn=min(mn,1+max(l,r));
            if(l<r)i=m+1;
            else j=m-1;
        }
        return t[k][n]=mn;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return sup(k,n);
    }
};