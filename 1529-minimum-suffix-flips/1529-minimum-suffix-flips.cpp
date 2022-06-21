class Solution {
public:
    int minFlips(string t) {
        bool fz=false;
        int c=0;
        for(int i=size(t)-1;i>=0;--i){
            if(t[i]=='1'){
                while(i>=0 && t[i]=='1')--i;
                c=c+(fz?2:1);
                ++i;
            }
            else fz=true;
        }
        return c;
    }
};