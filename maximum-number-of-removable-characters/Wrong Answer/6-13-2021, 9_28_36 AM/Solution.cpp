// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& r) {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpp;
        for(auto i:s)mps[i]++;
        for(auto i:p)mpp[i]++;
        int i;
        for(i=0;i<r.size();i++){
            if(mpp.count(s[r[i]])){
                if(p.length()>r[i] && p[r[i]]==s[r[i]]) return i;
                else{
                    if(mps[s[r[i]]]>mpp[s[r[i]]]){
                        // cout<<s[r[i]]<<" ";
                    mps[s[r[i]]]--;
                      // s.erase(r[i],1);  
                        
                    } 
                    else return i;
                }
            }
            else{
                 // cout<<s[r[i]]<<" ";
                
                mps[s[r[i]]]--;
                // s.erase(r[i],1);
                cout<<s<<" ";
            }
        }      
        return i-1;
        
        
    }
};