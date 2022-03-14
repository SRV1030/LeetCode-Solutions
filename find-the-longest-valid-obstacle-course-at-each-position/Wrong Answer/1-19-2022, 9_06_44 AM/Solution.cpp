// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

class Solution {
public:
    int uBound(int v[],int l,int h,int k){
        while(l<h){
            int m=l+(h-l)/2;
            if(v[m]<k) l=m+1;
            else h=m;            
        }
        return h;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
       vector<int>lis;
       int n=obstacles.size(); 
       lis.push_back(1); 
       int dp[n+1],l=1;        
       dp[0]=obstacles[0];
       for(int i=1;i<n;i++){
            if(dp[l-1]<=obstacles[i]){
                dp[l++]=obstacles[i];
                lis.push_back(i+1);
            }
           else{
               int x=uBound(dp,0,l-1,obstacles[i]);
               dp[x]=obstacles[i];
               lis.push_back(x);
           }
           
       }
       return lis;
    }
};