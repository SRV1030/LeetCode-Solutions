// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size();
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                int j=n-1;
                while(j>i){
                    if(a[j]>a[i])break;
                    j--;
                }
                cout<<i<<" "<<j<<" ";
                swap(a[i],a[j]);
                reverse(a.begin()+i+1,a.begin()+j);
                return; 
            }
        }
        sort(a.begin(),a.end());
    }
};