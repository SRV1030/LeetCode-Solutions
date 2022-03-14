// https://leetcode.com/problems/design-authentication-manager

class AuthenticationManager {
public:
    unordered_map<string,int>mp;
    int tt;
    AuthenticationManager(int timeToLive) {
        tt=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime+tt;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId)){
            if(mp[tokenId]<currentTime)mp.erase(tokenId);
            else mp[tokenId]=currentTime+tt;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        if(mp.empty()) return 0;
        for (auto it = mp.cbegin(); it != mp.cend();){
              if (it->second<=currentTime) mp.erase(it++);    // or "it = m.erase(it)" since C++11              
              else ++it;
            }
        return mp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */