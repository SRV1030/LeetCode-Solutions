class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,h=letters.size()-1;
        while(l<h){
            int m= l+(h-l)/2;
            if(letters[m]<=target)l=m+1;
            else h=m;
        }
        if(h==letters.size()-1 && letters[h]<=target) return letters[0];
        return letters[h];
    }
};