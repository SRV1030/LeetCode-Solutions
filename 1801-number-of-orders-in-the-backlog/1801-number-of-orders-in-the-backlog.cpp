class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<array<int,2>>b,s;
        long long res=0;
        for(auto&i:orders){
            res+=i[1];
            if(i[2])s.push({-i[0],i[1]});
            else b.push({i[0],i[1]});
            while(!s.empty() && !b.empty() && -s.top()[0]<=b.top()[0]){
                auto s1=s.top(),b1=b.top();
                s.pop(),b.pop();
                int exe=min(s1[1],b1[1]);
                res-=2*exe;
                if(s1[1]>exe) s.push({s1[0],s1[1]-exe});
                if(b1[1]>exe) b.push({b1[0],b1[1]-exe});
            }
        }
        return res % 1000000007;
    }
};