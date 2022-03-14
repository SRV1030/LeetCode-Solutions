// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>a(n);
        int i=0,j=n-1,x=1;
        if(n%2){
            while(i<j){
                a[i++]=x;
                a[j--]=(-1)*x;
                x++;
            }
            a[i]=0;
            return a;
        }
        else{
            while(i<j){
                a[i++]=x;
                a[j--]=(-1)*x;
                x++;
            }
            return a;
        }
    }
};