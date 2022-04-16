class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int>pq;
        for(int i=1;i<h.size();i++){
            int d=h[i]-h[i-1];
            if(d>0){
                pq.push(d);
                b-=d;
                if(b<0){
                    b+=pq.top();
                    pq.pop();
                    l--;     
                    if(b<0 || l<0) return i-1;
                }                
            }
        }
        return h.size()-1;
    }
};