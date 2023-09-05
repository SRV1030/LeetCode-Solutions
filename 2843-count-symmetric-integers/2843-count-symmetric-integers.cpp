class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(;low<=high;++low){
            string s=to_string(low);
            int t=0,n=size(s);
            for(int j = 0; j < n/2; ++j) { t += s[j] - s[n - j - 1]; }
            if(n%2 == 0 && t == 0) ans++;
        }
        return ans;
    }
};