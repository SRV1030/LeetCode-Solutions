// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    bool isSubSeq(string a,string b){
        int n=a.length();
        int m=b.length();
        int j=0;
        for(int i=0;i<n&&j<m;i++)
            if(a[i]==b[j])j++;
        return m==j;
    }
    int maximumRemovals(string s, string p, vector<int>& r) {
        int l=0,h=r.size(),ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            string temp=s;
            for(int i=0;i<m;i++)temp[r[i]]='$';
            if(isSubSeq(temp,p)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
        
    }
};