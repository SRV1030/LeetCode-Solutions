// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
    unordered_map<int,map<int,int>>mp;
    DetectSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1],c=0;
        for(auto&[k,v]:mp[y]){
            if(k==x)continue;
            int l=abs(k-x);
            if(y-l>=0)c+=v*mp[y-l][x]*mp[y-l][k];
            if(y+l<=1000)c+=v*mp[y+l][x]*mp[y+l][k];
        }
        return c;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */