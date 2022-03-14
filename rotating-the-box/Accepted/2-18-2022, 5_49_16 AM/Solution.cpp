// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r=box.size(),c=box[0].size();
        for(int i=0;i<r;i++){
            int ind=-1;
            for(int j=c-1;j>=0;j--){
                if(box[i][j]=='*') ind=-1;
                else if(box[i][j]=='.'){
                    if(ind==-1)ind=j;
                } 
                else{
                    if(ind!=-1){
                        box[i][ind--]=box[i][j];
                        box[i][j]='.';                        
                    }
                }
            }
        }
        vector<vector<char>> ans(c,vector<char>(r,'*'));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)ans[j][r-1-i]=box[i][j];
        return ans;
    }
};