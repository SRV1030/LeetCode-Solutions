// https://leetcode.com/problems/minimum-speed-to-arrive-on-time

class Solution {
public:
    bool ispos(vector<int>dist, int mid,double hour){
        double count = 0;
        int i;
        for(i = 0;i<dist.size()-1;i++) {
            double d = (double)dist[i]/mid;
            count += ceil(d);
            if(count>hour) return false;
        }
        double d = (double)(dist[dist.size()-1]/(double)mid);
        count += (d);
        return count <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,h=1000000000;
        while(l<h){
            int m=(l+h)/2;
            if(ispos(dist,m,hour)) h=m;
            else l=m+1;
        }
        return ispos(dist,h,hour)?h:-1;
    }
};