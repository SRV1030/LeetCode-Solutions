// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(mp.empty()){
            mp[start]=end;
            return true;
        }
        auto up=mp.upper_bound(start);
        if(up!=mp.end() && up->first>start && up->first<end) return false;
        up=prev(up);
        if(up->first<=start && up->second>start) return false;
        mp[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */