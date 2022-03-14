// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int findMinDifference(vector<string>& t) {
        sort(t.begin(),t.end(),[](string a,string b){
            
            int x,y;
            if(a=="00:00")x=1440;
            else x=stoi(a.substr(0,2))*60+stoi(a.substr(3,2));
            if(b=="00:00")y=1440;
            else y=stoi(b.substr(0,2))*60+stoi(b.substr(3,2));
            return x<y;
        });
        int x,y;
            if(t[0]=="00:00")x=1440;
            else x=stoi(t[0].substr(0,2))*60+stoi(t[0].substr(3,2));
        if(t[1]=="00:00")y=1440;
            else y=stoi(t[1].substr(0,2))*60+stoi(t[1].substr(3,2));
         return y-x;
    }
};