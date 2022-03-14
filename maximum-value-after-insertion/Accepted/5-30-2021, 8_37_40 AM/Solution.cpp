// https://leetcode.com/problems/maximum-value-after-insertion

class Solution {
public:
    string maxValue(string n, int x) {
        if(n[0]!='-'){
            int i;
            for(i=0;i<n.length();i++){
                if(x>n[i]-'0') break;
            }
            n.insert(i,to_string(x));
        }
        else{
            int i;
            for(i=1;i<n.length();i++){
                if(x<n[i]-'0') break;
            }
            n.insert(i,to_string(x));
            
        }
        return n;
        
    }
};