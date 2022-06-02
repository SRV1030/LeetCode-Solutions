class Solution {
public:
    #define li long long int
    int findT(vector<int>& n1, vector<int>& n2){
        unordered_map<li,int>mp;
        int c=0;
        for(auto&i:n1)mp[(li)i*i]++;
        for(int j=0;j<size(n2);++j)
            for(int k=j+1;k<size(n2);++k)c+=mp[(li)n2[j]*n2[k]];
        return c;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int c=findT(nums1,nums2);
        c+=findT(nums2,nums1);
        return c;
    }
};