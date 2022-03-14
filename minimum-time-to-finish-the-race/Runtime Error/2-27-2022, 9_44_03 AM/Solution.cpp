// https://leetcode.com/problems/minimum-time-to-finish-the-race

class Solution {
public:
    int n;
    long long int solve(vector<vector<long long int>>& v,int cT,int nL,int prev){
        if(nL==0)return 0;
        long long int mn=INT_MAX;
        for(int j=0;j<n;j++){
            long long int val=v[j][0];
            // if(val>1e9)continue;
            v[j][0]=v[j][0]*v[j][1];
            if(prev==-1){
                mn=min(mn,solve(v,cT,nL-1,j)+val);
            }
            else{
                if(prev!=j)mn=min(mn,solve(v,cT,nL-1,j)+val+cT);
                else{
                    mn=min(mn,solve(v,cT,nL-1,j)+val);
                    long long int val2=v[j][2];
                    v[j][0]=v[j][2]*v[j][1];
                    mn=min(mn,solve(v,cT,nL-1,j)+val2+cT);
                
                }
            }
            v[j][0]=val;
        }
        return mn;
    }
    int minimumFinishTime(vector<vector<int>>& tires, int cT, int nL) {
        n=tires.size();
        vector<vector<long long int>>v;
        for(auto &t:tires){
            t.push_back(t[0]);
            v.push_back({t[0],t[1],t[2]});            
        }
        return solve(v,cT,nL,-1);
    }
};