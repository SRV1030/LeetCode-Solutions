// https://leetcode.com/problems/happy-number

class Solution {
public:
    int getS(int n){
       int sum=0;
        while(n){
            int r=n%10;
            sum+=r*r;
            n/=10;
        } 
        return sum;
    }
    bool isHappy(int n){
        set<int>st;
        while(n!=1){
            st.insert(n);
            int sum= getS(n);
            if(sum==1) return true;
            if(st.count(sum)) return false;
            n=sum;
        }
        return true;
    }
};