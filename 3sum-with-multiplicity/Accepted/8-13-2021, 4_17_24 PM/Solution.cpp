// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int md=1e9+7;
    int threeSumMulti(vector<int>& arr, int t) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        for(auto& i:arr)mp[i]++;
        int c=0,n=arr.size();
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int s=arr[i]+arr[l]+arr[r];
                if(s==t){
                    if(arr[l]!=arr[r])c=(c%md+mp[arr[r]]%md)%md;
                    else c=(c%md+r%md-l%md)%md;
                    l++;
                }
                else if(s>t)r--;
                else l++;
            }
        }
        return c%md;
    }
};