// class Solution {
// public:
//     int maximumProduct(vector<int>& a) {
//         sort(a.begin(),a.end());
//         int n=a.size();
//         return max(a[n-1]*a[n-2]*a[n-3],max(a[0]*a[1]*a[2],a[0]*a[1]*a[n-1]));
        
//     }
// };


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mn1=10001,mn2=10001,mx1=-10001,mx2=-10001,mx3=-10001;
        for(auto& i:nums){
            if(i>mx1){
                mx3=mx2;
                mx2=mx1;
                mx1=i;
            }
            else if(i>mx2){                
                mx3=mx2;
                mx2=i;
            }
            else if(i>mx3)mx3=i;
            if(i<mn1){
                mn2=mn1;
                mn1=i;
            }else if(i<mn2)mn2=i;
        }
        return max(mn1*mn2*mx1,mx1*mx2*mx3);        
    }
};