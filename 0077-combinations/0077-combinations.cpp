class Solution {
public:    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        int i=0;
        vector<int>p(k,0);
        while(i>=0){
            p[i]++;
            if(p[i]>n) i--;
            else if(i==k-1)ans.push_back(p);
            else{
               i++;
               p[i]=p[i-1]; 
            } 
        }
        return ans;
    }
};