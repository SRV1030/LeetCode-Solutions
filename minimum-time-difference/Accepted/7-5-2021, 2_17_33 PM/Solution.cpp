// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int findMinDifference(vector<string>& t) {
    vector<int>t1;
       for(auto i:t){
           int x= stoi(i.substr(0,2))*60+stoi(i.substr(3,2));
           t1.push_back(x);
       } 
       sort(t1.begin(),t1.end());
        int mn=INT_MAX;
        for(int i=1;i<t.size();i++){
            mn=min(mn,t1[i]-t1[i-1]);
        }
        return min(mn,t1[0]-t1[t.size()-1]+24*60);
    }
};