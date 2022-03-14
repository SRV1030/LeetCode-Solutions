// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    bool isSubSequence(string str1, string str2,
                                 int m, int n)
{
     
   
    if (m == 0)
        return true;
    if (n == 0)
        return false;
 
   
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);
 
    return isSubSequence(str1, str2, m, n - 1);
}
    int maximumRemovals(string s, string p, vector<int>& r) {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpp;
        for(auto i:s)mps[i]++;
        for(auto i:p)mpp[i]++;
        int i;
        for(i=0;i<r.size();i++){
            if(mpp.count(s[r[i]])){
                if(p.length()>r[i] && p[r[i]]==s[r[i]] && mps[s[r[i]]]>mpp[s[r[i]]]){
                   
                    s.erase(r[i],1);
                    // cout<<t<<" ";
                    if(!isSubSequence(p,s,p.length(),s.length())) return i;
                } 
                else{
                    if(mps[s[r[i]]]>mpp[s[r[i]]]){
                    // cout<<i<<" ";
                        s.erase(r[i],1);
                    mps[s[r[i]]]--;
                    } 
                    else return i;
                }
            }
            else{
                // s.erase(r[i],1);
                mps[s[r[i]]]--;
                // cout<<s<<" ";
            }
        }      
        return i;
        
        
    }
};