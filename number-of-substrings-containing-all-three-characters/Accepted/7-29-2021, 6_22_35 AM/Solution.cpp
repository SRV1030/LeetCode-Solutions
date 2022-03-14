// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    bool check(vector<int>v){
        return v[0]>=1 && v[1]>=1 && v[2]>=1;
    }
    int numberOfSubstrings(string s) {
        vector<int>v(3);
        int i=0,j=0,n=s.size(),ans=0;
        while(i<n){
            v[s[i]-'a']++;
            if(!check(v)) i++;
            else{
                while(check(v)){
                    ans+=(n-i);
                    v[s[j]-'a']--;
                    j++;
                }
                i++;
            }
            
        }
        return ans;
    }
};