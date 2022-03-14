// https://leetcode.com/problems/detect-squares

class DetectSquares {
public:
        unordered_map<int, map<int, int>> mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point[1]][point[0]] += 1;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int px = point[0], py = point[1];
        for(auto it = mp[py].begin(); it != mp[py].end(); it++){
            if(it->first == px)
                continue;
            int x = it->first;
            int len = abs(x - px);
            if(py - len >= 0){
                ans += it->second * mp[py - len][x] * mp[py - len][px];
            }
            if(py + len <= 1000){
                ans += it->second * mp[py + len][x] * mp[py + len][px];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */