// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                int j=n-1;
                while(j>i){
                    if(a[j]>i)break;
                    j--;
                }
                cout<<i<<" "<<j<<" ";
                reverse(a.begin()+i,a.begin()+j+1);
                return; 
            }
        }
    }
};