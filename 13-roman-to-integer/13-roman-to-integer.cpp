class Solution {
public:
    int getval(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int res =0;
        for(int i=0;i<s.length();i++){
            int s1= getval(s[i]);
            if(i+1<s.length()){
               int s2= getval(s[i+1]);
                if(s1>=s2)res+=s1;
                else{
                    res+=s2-s1;
                    i++;
                }
            }
            else res+=s1;
        }
        return res;
    }
};