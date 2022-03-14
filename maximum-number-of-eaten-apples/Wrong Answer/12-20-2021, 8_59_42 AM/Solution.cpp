// https://leetcode.com/problems/maximum-number-of-eaten-apples

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        unordered_map<int,int>mp;
        int ac=0,c=0;
        for(int i=0;i<apples.size();i++){
            if(!mp.empty() && mp.count(i)){
                ac-=mp[i];
                mp.erase(i);
                // cout<<i<<"\n";
            } 
            if(apples[i]){
                ac+=apples[i];
                mp[i+days[i]]+=apples[i];
            }
            // cout<<c<<" ";
            if(ac>0)c++;
            
        }
        int cd=apples.size();
        for(auto & [k,v]:mp){
            int d=k-cd;
            cout<<k<<" "<<v<<" ";
            c+= min(d,v);
            cd=k;
        }
        cout<<c<<" ";
        return c;
    }
};