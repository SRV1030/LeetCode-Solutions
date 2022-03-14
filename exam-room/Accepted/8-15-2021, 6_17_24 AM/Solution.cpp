// https://leetcode.com/problems/exam-room

class ExamRoom {
public:
    set<int>s;
    int capacity;
    ExamRoom(int n) {
        capacity=n;
    }
    
    int seat() {
        if(s.size()==capacity) return -1;
        if(s.empty()){
            s.insert(0);
            return 0;
        }
        int prev=0,cur=0,mid=-1,middist=0;
        bool f=false;
        for(auto& i:s){
            cur=i;
            if(!f && cur-prev>middist){
                middist=cur-prev;
                mid=0;
            }
            f=true;
            if((cur-prev)/2>middist){
                middist=(cur-prev)/2;
                mid=prev+middist;
            }
            prev=i;
        }
        if(capacity-1-cur>middist)mid=capacity-1;
        s.insert(mid);
        return mid;
        
    }
    
    void leave(int p) {
        s.erase(p);
        return;
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */