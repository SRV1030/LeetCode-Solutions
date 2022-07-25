class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));
        for(int i=1;i<size(arr)-1;++i)if(arr[i-1]-arr[i]!=arr[i]-arr[i+1])return false;
        return true;
    }
};