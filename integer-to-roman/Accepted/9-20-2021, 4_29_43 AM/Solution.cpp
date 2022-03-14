// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
   string intToRoman(int num) {
        vector<int>v{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>s{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string st="";
int i=v.size()-1;
        while(num>0){
            int div=num/v[i];
            num=num%v[i];
            while(div>0){
                st+=s[i];
                div--;
            }
            i--;
        }
        return st;
    }
};