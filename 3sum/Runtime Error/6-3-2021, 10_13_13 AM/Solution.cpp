// https://leetcode.com/problems/3sum

class Solution {
public:
    int bsearch(vector<int>& n,int l,int r,int k){
        while(l<=r){
            int m=l+(r-l)/2;
            if(n[m]==k) return m;
            else if(n[m]>k)r=m-1;
            else l=m+1;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& n) {
      vector<vector<int>> ans;
        int m=n.size();
        if(m<3)return ans;
        sort(n.begin(),n.end());
        for(int i=0;i<m-2;i++){
             if(i>0 && n[i]==n[i-1])
                continue;
            int l=i+1;
            int r=m-1;
            while(l<r){
                
                int s=n[l]+n[r]+n[i];
                if(s==0){
                    ans.push_back({n[i],n[l],n[r]});
                    while(l<r && n[l]==n[l+1])l++;
                    while(l<r && n[r-1]==n[r])r++;
                    l++;
                    r--;                    
                }
                else if(s>0)r--;
                else l++;
            }
        }
        return ans;
    }
};