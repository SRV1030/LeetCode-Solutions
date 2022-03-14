// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char st=s[0],stv=s[1],e=s[3],ev=s[4];
        while(st<=e){
            char x=stv;
            while(x<=ev){
                string t;
                t+=st;
                t+=x;
                x++;
                ans.push_back(t);
            }
            st++;
        }
        return ans;
    }
};