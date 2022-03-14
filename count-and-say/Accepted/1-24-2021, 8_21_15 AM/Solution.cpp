// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        int i=1;
        int count=1;
        char check;
        while(i<n){
            string temp="";
            check=s[0];
            count=1;
            for(int i=1;i<s.size();i++){
                if(check==s[i]){
                    count++;
                }else{
                    temp+=to_string(count);
                    temp.push_back(check);
                    check=s[i];
                    count=1;
                }
            }
            temp+=to_string(count);
            temp.push_back(check);    
            s=temp;
            i++;
        }       
        return s;
    }
};