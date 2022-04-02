class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;v.push_back(i++));
        int rem=0;
        k--;
        while(v.size()>1){
            rem=(rem+k)%v.size();
            v.erase(v.begin()+rem);
        }
        return v[0];
    }
};