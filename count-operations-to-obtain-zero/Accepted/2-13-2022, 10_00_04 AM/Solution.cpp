// https://leetcode.com/problems/count-operations-to-obtain-zero

class Solution {
public:
    int countOperations(int num1, int num2) {
        int c=0;
        while(num1>0 && num2>0){
            if(num1>num2) {
                c+=num1/num2;
                num1=num1%num2;
            }                
            else {
                c+=num2/num1;
                num2=num2%num1;
            }     
        }
        return c;
    }
};