// https://leetcode.com/problems/seat-reservation-manager

class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        for(int i=1;i<=n;st.insert(i++));
    }
    
    int reserve() {
        if(st.empty()) return 0;
        int x=*st.begin();
        st.erase(x);    
        return x;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */