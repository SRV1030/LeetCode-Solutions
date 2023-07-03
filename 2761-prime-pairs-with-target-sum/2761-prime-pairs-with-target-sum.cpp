class Solution {
public:
    vector<vector<int>> findPrimePairs(int num) {
        vector<bool> isPrime(num+1);
        vector<vector<int>> ans;
        for (int i = 2; i <= num; i++) isPrime[i] = true;
        for (int i = 2; i <= num; i++)
            if (isPrime[i])
                for (int j = i * 2; j <= num; j += i) 
                    isPrime[j] = false; 
        set<int>st;
        for (int i = 2; i <= num; i++)
            if(isPrime[i])st.insert(i);
        for(auto&i:st)
            if(st.count(num-i)){
                if(i>(num-i)) return ans;
                ans.push_back({i,num-i});
            }
        return ans;
    }
};