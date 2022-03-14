// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
public:
    int bs(vector<int>& days,int cd, int target){
        int i=cd,j=days.size()-1;
        while(i<=j){
            int m=i+((j-i)>>1);
            if(days[m]==target || (days[m]<target && m+1<days.size() && days[m+1]>target)) return m+1;
            else if(target>days[m])i=m+1;
            else j=m-1;            
        }
        return -1;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            int d6=bs(days,i,days[i]+6),d29=bs(days,i,days[i]+29),a=costs[0],b=costs[1],c=costs[2];
            if(i+1<n)a+=ans[i+1];
            if(d6>=0 && d6<n)b+=ans[d6];
            if(d29>=0 && d29<n)c+=ans[d29];
            ans[i]=min({a,b,c});
        }      
        return ans[0];
    }
};