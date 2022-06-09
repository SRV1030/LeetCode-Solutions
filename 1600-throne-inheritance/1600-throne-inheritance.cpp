class ThroneInheritance {
public:
    string k;
    unordered_map<string,pair<bool,vector<string>>>mp;
    ThroneInheritance(string kingName) {
        k=kingName;
    }
    
    void birth(string parentName, string childName) {
        mp[parentName].second.push_back(childName);
    }
    
    void death(string name) {
        mp[name].first=true;
    }
    void succ(string n,vector<string>&res){
        if(!mp[n].first)res.push_back(n);
        for(auto&i:mp[n].second)succ(i,res);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>res;
        succ(k,res);
        return res;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */