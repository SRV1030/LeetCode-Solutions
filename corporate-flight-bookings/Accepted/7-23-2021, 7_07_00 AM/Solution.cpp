// https://leetcode.com/problems/corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n,0);
        for(auto& i:bookings){
            v[i[0]-1]+=i[2];
            if(i[1]<n)v[i[1]]-=i[2];
        }
        for(int i=1;i<n;i++)v[i]+=v[i-1];
        return v;
    }
};