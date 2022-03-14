// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int res=0;
    void dfs(vector<int>&v,int ind){
        if(ind==v.size())res++;
        else{
            for(int i=ind;i<v.size();i++){
                if((v[i]%(ind+1)==0 || (ind+1)%v[i]==0)){
                    swap(v[ind],v[i]);
                    dfs(v,ind+1);
                    swap(v[ind],v[i]);
                }
            }            
        }
    }
    int countArrangement(int n) {
        if(n<=2) return n;
        vector<int>v;
        for(int i=1;i<=n;i++)v.push_back(i);
        dfs(v,0);
        return res;
    }
};