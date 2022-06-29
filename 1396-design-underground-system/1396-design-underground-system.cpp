class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>mps;
    unordered_map<string,pair<int,int>>mpr;
        
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mps[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto&[p,t0]=mps[id];
        string r=p+"-"+stationName;
        mpr[r].first+=t-t0;
        mpr[r].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string r=startStation+"-"+endStation;
        return mpr[r].first/(double)mpr[r].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */