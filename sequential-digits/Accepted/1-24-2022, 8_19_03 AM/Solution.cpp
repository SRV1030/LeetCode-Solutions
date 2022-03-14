// https://leetcode.com/problems/sequential-digits

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string l=to_string(low),h=to_string(high);
        string p="123456789";
        int s=l.size(),e=h.size();
        vector<int> ans;
        for(int sz=s;sz<=e;sz++){
            for(int i=0;i+sz<10;i++){
                int v=stoi(p.substr(i,sz));
                if(v<low) continue;
                if(v>high) return ans;
                ans.push_back(v);
            }
        }
        return ans;
    }
};