// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter

class Solution {
public:
    int minTimeToType(string word) {
        int c=0;
        char prev='a';      
        for(int i=0;i<word.length();i++)
        {
           int a=min(abs(word[i]%26-prev%26)%26,abs(26-abs(word[i]%26-prev%26))%26);     //find the minimum jump needded, whether you want to jump clockwise or anticlockwise       
            prev=word[i];
            c+=a+1;//adding 'a' to our answer with 1 as needed for each step
            // cout<<a<<" "<<c<<',';
        }
       // cout<<"\n";
        return c;
    }
};