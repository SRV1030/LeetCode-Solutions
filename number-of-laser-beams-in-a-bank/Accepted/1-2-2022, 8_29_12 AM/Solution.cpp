// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int c=0,pc=0,ans=0;
        for(auto& i:bank[0])if(i=='1')pc++;
        for(int i=1;i<bank.size();i++){
            for(auto&j:bank[i])if(j=='1')c++;
            if(c==0)continue;
            ans+=(pc*c);
            pc=c;
            c=0;
        }
        return ans;
    }
};