// https://leetcode.com/problems/corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n,0);
        for(auto i:bookings)
            for(int j=i[0]-1;j<i[1];j++){
                v[j]+=i[2];
            }
        return v;
    }
};