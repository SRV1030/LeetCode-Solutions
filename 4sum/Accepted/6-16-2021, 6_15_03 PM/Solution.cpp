// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {
        set<vector<int>>s;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    int sum=a[i]+a[j]+a[l]+a[r];
                    if(sum==t){
                        s.insert({a[i],a[j],a[l],a[r]});
                        l++;
                        r--;
                    }
                    else if(sum>t) r--;
                    else l++;
                }
            }
        }
        vector<vector<int>> v(s.begin(),s.end());
        return v;        
    }
};