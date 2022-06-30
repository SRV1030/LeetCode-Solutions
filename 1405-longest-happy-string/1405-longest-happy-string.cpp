class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        string ans;
        char prev='z';
        while(!pq.empty()){
            auto[v,c]=pq.top();
            pq.pop();
            if(c==prev){
                if(pq.empty()) return ans;
                auto[v1,c1]=pq.top();
                pq.pop();
                ans+=c1;
                --v1;
                if(v1)pq.push({v1,c1});
                pq.push({v,c});
                prev=c1;
            }else{
                if(v>=2){
                    v-=2;
                    ans+=c;
                    ans+=c;
                }
                else{
                    --v;
                    ans+=c;
                }
                if(v)pq.push({v,c});
                prev=c;
            }
        }
        return ans;
    }
};