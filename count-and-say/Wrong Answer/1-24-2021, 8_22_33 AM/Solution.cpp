// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        int i=1;
        int count=1;
        while(i<n){
            string temp="";
            char ch=s[0];
            count=1;
            for(i=1;i<s.size();i++){
                if(ch==s[i]) count++;
                else{
                    temp.push_back(count);
                    temp.push_back(ch);
                    count=1;
                    ch=s[i];
                }
            }
            temp.push_back(count);
            temp.push_back(ch);
            s=temp;
            i++;
        }
        return s;
    }
};