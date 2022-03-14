// https://leetcode.com/problems/pancake-sorting

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>res;
        for(int i=arr.size()-1;i>0;i--){
            for(int j=1;j<=i;j++){
                if(arr[j]==i+1){
                    reverse(arr.begin(),arr.begin()+j+1);
                    res.push_back(j+1);
                    break;
                }
            }
             reverse(arr.begin(),arr.begin()+i+1);
                    res.push_back(i+1);
        }
        return res;
        
    }
};