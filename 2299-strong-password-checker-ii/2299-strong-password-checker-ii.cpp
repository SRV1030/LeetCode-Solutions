class Solution {
public:
    bool strongPasswordCheckerII(string p) {
         int n= size(p);
         if(n<8) return false; 
         bool uc=false,lc=false,sp=false,dg=false;
        char pv='|';
        for(auto&i:p){
            if(i==pv)return false;
            if(isdigit(i))dg=true;
            else if(i>='a' && i<='z')lc=true;
            else if(i>='A' && i<='Z')uc=true;
            else sp=true;
            pv=i;
        }
       return dg&&lc&&uc&&sp;        
    }
};