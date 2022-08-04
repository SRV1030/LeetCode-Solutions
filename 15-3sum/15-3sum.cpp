class Solution {
public:
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
                    while(l<r && n[r]==n[r-1])r--;
                    l++;
                    r--;                    
                }
                else if(s<0)l++;
                else r--;
            }
        }
        return ans;
    }
};