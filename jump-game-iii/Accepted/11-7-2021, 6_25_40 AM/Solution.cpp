// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size() || start<0 || arr[start]==-100) return false;
        if(arr[start]==0) return true;
        int t=arr[start];
        arr[start]=-100;
        bool p=canReach(arr,start+t),m=canReach(arr,start-t);
        arr[start]=t;
        return p||m;        
    }
};