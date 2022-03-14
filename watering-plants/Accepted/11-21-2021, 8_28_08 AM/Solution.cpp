// https://leetcode.com/problems/watering-plants

class Solution {
public:
    int wateringPlants(vector<int>& p, int cap) {
        int c=cap,s=0;
        for(int i=0;i<p.size();i++){
            if(p[i]<=cap){
                s++;
                cap-=p[i];
            }
            else{
                s+=2*i;
                cap=c;
                i--;
            }
        }
        return s;
    }
};