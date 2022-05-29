class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int l= pow(2, n) - 1;
        if(k-1==l/2)return '1';
        else if(k-1<l/2) return findKthBit(n-1,k);
        return findKthBit(n-1,l-k+1)=='0'?'1':'0';
    }
};