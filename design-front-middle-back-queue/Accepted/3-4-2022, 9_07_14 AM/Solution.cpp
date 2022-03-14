// https://leetcode.com/problems/design-front-middle-back-queue

class FrontMiddleBackQueue {
public:
    deque<int>dq1,dq2;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        dq1.push_front(val);
        if(dq1.size()-dq2.size()>1){
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        if(dq1.size()==dq2.size())dq1.push_back(val);
        else{
            dq2.push_front(dq1.back());
            dq1.pop_back();
            dq1.push_back(val);
        }
    }
    
    void pushBack(int val) {
        dq2.push_back(val);
        while(dq2.size()>dq1.size()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
    }
    
    int popFront() {
        if(dq1.empty()) return -1;
        int ans=dq1.front();
        dq1.pop_front();
        while(dq2.size()>dq1.size())
        {
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        //one more element in dq1
        //middle element is in back of dq1
        if(dq1.empty()) return -1;
        int ans=dq1.back();
        dq1.pop_back();
        while(dq2.size()>dq1.size()) 
        {
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return ans;
    }
    
    int popBack() {
        if(dq1.empty()) return -1;
        if(dq2.empty()) //only one element i.e. in dq1
        {
            int ans=dq1.back();
            dq1.pop_back();
            return ans;
        }
        int ans=dq2.back();
        dq2.pop_back();
        while(dq1.size()-dq2.size()>1) //more than one element in dq1
        {
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */