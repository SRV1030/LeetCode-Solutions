class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(size(arr)<3) return false;
        for(int i=0;i<size(arr)-2;++i)
            if(arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) return true;
        return false;
    }
};