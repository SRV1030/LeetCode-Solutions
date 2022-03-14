// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        int l=0,n=s.size();
        if(k==1) return n;
        if(k > n || n==0) return 0;
        unordered_map<char,int>fr;
        for(auto&i:s)fr[i]++;
        while(l<n && fr[s[l]]>=k)l++;
        if(l>=n-1) return l;
        int ls1=longestSubstring(s.substr(0,l),k);
        while(l<n && fr[s[l]]<k)l++;
        int ls2=l<n?longestSubstring(s.substr(0,l),k):0;
        return max(ls1,ls2);
    }
};