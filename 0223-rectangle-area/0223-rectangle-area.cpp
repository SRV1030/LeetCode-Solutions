class Solution {
public:
    int getArea(int x1,int y1,int x2,int y2){
        return abs(x1-x2)*abs(y1-y2);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ax=getArea(ax1,ay1,ax2,ay2);
        int bx=getArea(bx1,by1,bx2,by2);
        int x1=max(ax1,bx1);
        int y1=max(ay1,by1);
        int x2=min(bx2,ax2);
        int y2=min(by2,ay2);
        int com=(x2<=x1 || y2<=y1)?0:getArea(x1,y1,x2,y2);
        return ax+bx-com;
    }
};