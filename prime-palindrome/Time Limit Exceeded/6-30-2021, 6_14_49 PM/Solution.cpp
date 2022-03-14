// https://leetcode.com/problems/prime-palindrome

class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        if(n==2 || n==3 || n==5 || n==7||n==11) return true;
        if(n%2==0 || n%3==0) return false;
         for (int i=5; i*i<=n; i=i+6) 
            if (n%i == 0 || n%(i+2) == 0) 
                return false;   
        return true;
    }
    bool isPal(int n){
        if(n<=10) return true;
        string s=to_string(n);
        int i=0,j=s.size();
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int primePalindrome(int N) {
        if (1e7 <= N and N <= 1e8)
            N = 100030001;
        while(1){
            while(!isPal(N)) N++;
            if (isPrime(N))
                return N;
            N++;
        }
        return -1;
    }
};