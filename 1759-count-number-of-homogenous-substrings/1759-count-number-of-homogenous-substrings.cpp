class Solution {
public:
    int md=1e9+7;
    int countHomogenous(string s) {
        long long int c=1,sum=s.size();
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])c++;
            else{
                sum=(sum+(c*(c-1))/2);
                sum%=md;
                c=1;
            }
        }
        if(c!=1)sum+=(c*(c-1))/2;
        return sum%md;
    }
};