// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    // vector<vector<pair<int,int>>>dp;
    // pair<int,int> util(vector<int>& arr,int i,int j){
    //     if(i==j)return {arr[i],0};
    //     if(dp[i][j].first!=-1) return dp[i][j];
    //     int mns=INT_MAX,mxPe=0;
    //     for(int k=i;k<j;k++){
    //       auto p1 = util(arr, i,k);
    //       auto p2 = util(arr, k+1,j);
    //       if(p1.second+p2.second + p1.first*p2.first < mns){
    //             mns = p1.second+p2.second + p1.first*p2.first;
    //             mxPe = max(p1.first,p2.first);
    //         }     
    //     }
    //     return dp[i][j]={mxPe,mns};
    // }
    // int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     dp=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(n,{-1,-1}));
    //     return util(arr,0,n-1).second;
    // }
    int mctFromLeafValues(vector<int>& arr) {
        int mns=0;
        while(arr.size()>1){
            int mnp=INT_MAX,idx=-1;
            for(int i=0;i<arr.size()-1;i++){
                if(arr[i]*arr[i+1]<mnp){
                    mnp=arr[i]*arr[i+1];
                    idx=arr[i]>arr[i+1]?i+1:i;
                }
            }
            mns+=mnp;
            arr.erase(arr.begin()+idx);
        }
        return mns;
    }
};