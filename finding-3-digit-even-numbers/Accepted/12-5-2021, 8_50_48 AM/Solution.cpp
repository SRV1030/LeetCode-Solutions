// https://leetcode.com/problems/finding-3-digit-even-numbers

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>o,e;
        set<int>ans;
        for(auto& i:digits)
            if(i%2)o.push_back(i);
            else e.push_back(i);
        if(e.empty())return {};
        if(!o.empty()){
            for(int i=0;i<o.size();i++)
                for(int j=0;j<o.size();j++){
                    if(i!=j){
                        for(int k=0;k<e.size();k++)
                            ans.insert(o[i]*100+o[j]*10+e[k]);
                    }
                }
            for(int i=0;i<o.size();i++)
                for(int j=0;j<e.size();j++)
                    for(int k=0;k<e.size();k++){
                        if(j!=k){
                            ans.insert(o[i]*100+e[j]*10+e[k]);
                            if(e[j]!=0) ans.insert(e[j]*100+o[i]*10+e[k]);
                        }
                    }            
                    
        }
        for(int i=0;i<e.size();i++)            
                for(int j=0;j<e.size();j++){
                        for(int k=0;k<e.size();k++)
                            if(e[i]!=0 && i!=j && i!=k && j!=k)ans.insert(e[i]*100+e[j]*10+e[k]);
                    }
        vector<int>res(ans.begin(),ans.end());    
        return res;
        
    }
};