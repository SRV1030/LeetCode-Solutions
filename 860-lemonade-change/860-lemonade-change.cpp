class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fs=0,ts=0;
        for(auto&i:bills){
            if(i==5)fs+=5;
            else if(i==10){
                ts+=i;
                fs-=5;
                if(fs<0) return false;
            }else{
                if(ts>0){
                    ts-=10;
                    fs-=5;
                }
                else fs-=15;
                if(ts<0 || fs<0) return false;
            }
        }
        return true;
    }
};