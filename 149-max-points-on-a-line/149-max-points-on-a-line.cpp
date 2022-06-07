class Solution {
public:
    double slope(vector<int> a,vector<int> b){
        if(a[1]==b[1]) return INT_MAX;
        else return (double)(a[0]-b[0])/(double)(a[1]-b[1]);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(),mx=1;
        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++){
                double sl=slope(points[i],points[j]);
                mp[sl]++;
                if(mp[sl]+1>mx)mx=mp[sl]+1;
            }
        }
        return mx;
    }
};