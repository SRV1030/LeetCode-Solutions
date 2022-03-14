// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size() == 1 && target[0] != 1) return false;
        long long int s=0;
        priority_queue<int>pq;
        for(auto& i:target){
            s+=i;
            pq.push(i);
        }
        while(true){
            int mx=pq.top();
            int dif=s-mx;
            if(mx==1 || dif==1)return true;
            int c=mx%dif;
            if(mx-dif<=0 || c==0)return false;
            pq.pop();
            pq.push(c);
            s=dif+c;
        }
        return true;
    }
};