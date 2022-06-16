class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fs=0,ts=0;
        for(auto&i:bills){
            if(i==5)fs++;
            else if(i==10) fs--,ts++;
            else{
                if(ts)ts--,fs--;
                else fs-=3;
            }
            if(fs<0) return false;
        }
        return true;
    }
};