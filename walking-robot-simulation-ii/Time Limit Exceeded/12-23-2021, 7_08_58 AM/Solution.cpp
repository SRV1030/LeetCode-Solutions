// https://leetcode.com/problems/walking-robot-simulation-ii

class Robot {
public:
    string dir="East";
    int x=0,y=0;
    int w,h;
    Robot(int width, int height) {
        w=width;
        h=height;
    }
    
    void step(int num) {
        while(num--){            
            if(dir=="East"){
                if(x+1>=w){
                    dir="North";
                    y++;
                }
                else x++;
            }
            else if(dir=="West"){
                if(x-1<0){
                    dir="South";
                    y--;
                }
                else x--;
            }
            else if(dir=="South"){
                if(y-1<0){
                    dir="East";
                    x++;
                }
                else y--;
            }
            else if(dir=="North"){
                if(y+1>=h){
                    dir="West";
                    x--;
                }
                else y++;
            }            
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */