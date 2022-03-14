// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        vector<vector<int>>s;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=0;i<n-3;i++){
            if(i==0 || a[i]!=a[i-1])
                for(int j=i+1;j<n-2;j++){
                    if(j==i+1 || a[j]!=a[j-1]){
                        int l=j+1,r=n-1;
                        while(l<r){
                            int sum=a[i]+a[j]+a[l]+a[r];
                            if(sum==t){
                                s.push_back({a[i],a[j],a[l],a[r]});
                                l++;
                                r--;
                            }
                            else if(sum>t) r--;
                            else l++;
                        }
                    }
                }
        }
        return s;
    }
};