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
        sort(v.begin(),v.end());
        int n=v.size();
        for(int i=0;i<n;i++){
            int ind=search(v,t-v[i],i+1,n-1);
            if(ind!=-1) return{i,ind};
        }
        return {-1,-1};
    }
};