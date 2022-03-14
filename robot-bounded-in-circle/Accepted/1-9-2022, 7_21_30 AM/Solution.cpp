// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string ins) {
        int x=0,y=0,dx=1,dy=0;
        for(char c:ins){
            switch(c){
                case 'G':
                    x+=dx;
                    y+=dy;
                    break;
                case 'L':
                    if(dy){
                        dx*=-1;
                        dy*=-1;
                    }
                    swap(dx,dy);
                    break;
                case 'R':
                    if(dx){
                        dx*=-1;
                        dy*=-1;
                    }
                    swap(dx,dy);
                    break;    
                    
            }
        }
        return (x==0&&y==0)||dx!=1;
        
    }
};