class UndergroundSystem {
public:
    unordered_map<string,pair<int,int>>mpr;
    unordered_map<int,pair<string,int>>mps;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mps[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto&[p,v]=mps[id];
        string des=p+"-"+stationName;
        mpr[des].first+=t-v;
        mpr[des].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string des=startStation+"-"+endStation;
        return mpr[des].first/(double)mpr[des].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */