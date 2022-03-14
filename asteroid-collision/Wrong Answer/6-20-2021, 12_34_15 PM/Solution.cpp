// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        for(int i=0;i<a.size()-1;i++){
            if((a[i]<0 && a[i+1]>=0)||(a[i]>=0 && a[i+1]<0)){
                int s=a[i]+a[i+1];
                if(s<=0){
                    a.erase(a.begin()+i);
                    a.erase(a.begin()+i);
                    i-=2;
                }
                else{
                    a[i]=max(a[i],a[i+1]);
                    a.erase(a.begin()+i+1);
                    i--;
                }
            }
        }
        return a;
    }
};