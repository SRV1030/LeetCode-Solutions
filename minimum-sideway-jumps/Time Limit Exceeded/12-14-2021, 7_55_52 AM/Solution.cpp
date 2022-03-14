// https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
public: int mnj=INT_MAX;
    void jump(int side,int j,vector<int>& obs,int cp){
        if(cp==obs.size()-1){ 
            // cout<<j<<" "<<side<<"\n";
            if(j<mnj)mnj=j;
            return;
        }    
        // cout<<cp<<" "<<obs[cp]<<" "<<side<<"\n";
        if(obs[cp+1]!=side) jump(side,j,obs,cp+1);
        else{            
            for(int i=1;i<=3;i++){
                if(i==side || obs[cp]==i )continue;
                jump(i,j+1,obs,cp);
            }
        }
        
        
    }
    int minSideJumps(vector<int>& obs) {
        jump(2,0,obs,0);
        return mnj;
    }
};