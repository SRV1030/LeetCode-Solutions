// https://leetcode.com/problems/flood-fill

class Solution {
public: 
    void ff(vector<vector<int>>& img,int sr,int sc,int &nc,int stpx){
        if(sr<0 || sr>=img.size() || sc<0 || sc>=img[0].size() || img[sr][sc]!=stpx) return;
        img[sr][sc]=nc;
        ff(img,sr+1,sc,nc,stpx);
        ff(img,sr,sc+1,nc,stpx);
        ff(img,sr-1,sc,nc,stpx);
        ff(img,sr,sc-1,nc,stpx);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc]) return image;
        ff(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};