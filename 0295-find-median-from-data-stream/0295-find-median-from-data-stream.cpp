class MedianFinder {
public: priority_queue<int>mxhp;
        priority_queue<int,vector<int>,greater<int>>mnhp;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxhp.empty())mxhp.push(num);
        else{
            if(num>mxhp.top()){
                if(mxhp.size()==mnhp.size()){
                    mnhp.push(num);
                    int x=mnhp.top();
                    mnhp.pop();
                    mxhp.push(x);
                }
                else mnhp.push(num);                
            }
            else{
                if(mxhp.size()>mnhp.size()){
                    mxhp.push(num);
                    int x=mxhp.top();
                    mxhp.pop();
                    mnhp.push(x);
                }
                else mxhp.push(num);         
            }
        }
    }
    
    double findMedian() {
        if((mxhp.size()+mnhp.size())%2) return mxhp.top();
        else return (mnhp.top()+mxhp.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */