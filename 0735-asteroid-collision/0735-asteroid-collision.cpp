class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>v;
        for(int i=0;i<a.size();i++){
            if(v.empty())v.push_back(a[i]);
            else if(v[v.size()-1]>=0 && a[i]<0){
                bool f=0;
                while(!v.empty() && v[v.size()-1]>=0 && v[v.size()-1]<=abs(a[i])){
                    if(v[v.size()-1]==abs(a[i])) {
                        f=1;
                        
                    v.pop_back();
                        break;
                    }
                    v.pop_back();
                }
                
                if(!f && (v.empty()|| v[v.size()-1]<=0))v.push_back(a[i]);
            }
            else v.push_back(a[i]);
        }
        return v;
        
    }
};