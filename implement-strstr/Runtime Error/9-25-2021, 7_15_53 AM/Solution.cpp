// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nn=needle.length(),nh=haystack.length(),hn=0,hh=0;
        if(!nn) return 0;
        if(nn>nh) return -1;
        for(int i=0;i<nn;i++){
            hn+=needle[i]*pow(3,i);
            hh+=haystack[i]*pow(3,i);
        }
        if(hh==hn)
                if(haystack.substr(0,nn)==needle) return 0;
        for(int i=1;i<nh-nn+1;i++){            
            hh-=haystack[i-1];
            hh/=3;
            hh+=haystack[i+nn-1]*pow(3,nn-1);
            if(hh==hn)
                if(haystack.substr(i,nn)==needle) return i;
        }
        return -1;
    }
};