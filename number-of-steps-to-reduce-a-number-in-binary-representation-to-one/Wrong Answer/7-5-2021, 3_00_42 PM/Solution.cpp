// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

class Solution {
public:
    int numSteps(string s) {
        int n=s.length()-1,ans=0;
        while(n>=0){
            if(s[n]=='1'){
                int j=n-1;
                while(j>=0 && s[j]=='1')j--;
                if(j<0)return ans+=n+2;
                ans+=n-j+1;
                s[j]=1;
                n=j;
            }
            else{
                ans++;
                n--;
                
            }
        }
        return ans;
    }
};