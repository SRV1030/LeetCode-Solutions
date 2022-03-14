// https://leetcode.com/problems/two-sum

class Solution {
    int search(vector<int> v,int k,int l,int h){
        while(l<=h){
            int m=l+(h-l)/2;
            if(v[m]==k)return m;
            else if(v[m]>k)h=m-1;
            else l=m+1;            
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& v, int t) {
        // sort(v.begin(),v.end());
        int n=v.size();
        for(int i=1;i<n-1;i++){
            auto ind=find(v.begin()+i,v.end(),t-v[i-1]);
            int j=ind-v.begin();
            if(ind!=v.end()) return{i-1,j};
        }
        return {-1,-1};
    }
};