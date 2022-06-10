class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& l) {
        vector<double>angles;
        int ans=0;
        for(auto&p:points){
            if(p[0]==l[0] && p[1]==l[1])++ans;
            else angles.push_back(atan2(p[1]-l[1],p[0]-l[0])*180/M_PI);
        }
        sort(begin(angles),end(angles));
        int n=size(angles),mx=0;
        for(int i=0,j=0;i<n*2;++i){
            if(360*(i>=n)+angles[i%n]-360*(j>=n)-angles[j%n]>angle)++j;
            mx=max(mx,i-j+1);
        }
        return ans+mx;
    }
};