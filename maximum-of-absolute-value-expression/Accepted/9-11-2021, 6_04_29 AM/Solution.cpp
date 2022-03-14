// https://leetcode.com/problems/maximum-of-absolute-value-expression

class Solution {
public:int n;
    int util(vector<int>v){
      int mx1=INT_MIN,mx2=INT_MIN,mn1=INT_MAX,mn2=INT_MAX;
        for(int i=0;i<n;i++){
            int s=v[i]+i,d=v[i]-i;
            if(mx1<s)mx1=s;
            if(mn1>s)mn1=s;
            if(mx2<d)mx2=d;
            if(mn2>d)mn2=d;
        }
        return max(mx1-mn1,mx2-mn2);
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        n=arr1.size();
        vector<int> add(n),sub(n);
        for(int i=0;i<n;i++){
            add[i]=arr1[i]+arr2[i];
            sub[i]=arr1[i]-arr2[i];
        }
        return max(util(add),util(sub));
    }
};