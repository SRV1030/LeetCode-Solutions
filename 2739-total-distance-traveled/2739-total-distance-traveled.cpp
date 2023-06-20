class Solution {
public:
    int distanceTraveled(int a, int b) {
        return (a + min((a - 1) / 4, b)) * 10;
    }      
    
};