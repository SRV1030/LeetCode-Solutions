// https://leetcode.com/problems/student-attendance-record-ii

// class Solution {
// public:
//     int md=1e9+7;
//     int util(int n,int Lcount,bool hasA){
//         if(!n) return 1;
//         int t=0;
//         if(!hasA){
//             t+=util(n-1,0,true);
//             t%=md;
//         }
//         if(Lcount<2){
//             t+=util(n-1,Lcount+1,false);
//             t%=md;
//         }
//         t+=util(n-1,0,hasA);
//         t%=md;
//         return t;
        
//     }
//     int checkRecord(int n) {
//         return util(n,0,false);
//     }
// };
#define li long long int
class Solution {
public:
    int md=1e9+7;
    int checkRecord(int n) {
        if(n==1) return 3;
        int t[n+1][3][2];
        t[1][0][0]=1;
        t[1][0][1]=1;
        t[1][1][0]=1;
        t[1][1][1]=0;
        t[1][2][0]=0;
        t[1][2][1]=0;
        for(int i=2;i<=n;i++){            
            t[i][0][0]=((li)t[i-1][0][0]+(li)t[i-1][1][0]+(li)t[i-1][2][0])%md;
            t[i][0][1]=((li)t[i-1][0][0]+(li)t[i-1][1][0]+(li)t[i-1][2][0]+(li)t[i-1][1][1]+(li)t[i-1][0][1]+(li)t[i-1][2][1])%md;
            t[i][1][0]=t[i-1][0][0]%md;
            t[i][1][1]=t[i-1][0][1]%md;
            t[i][2][0]=t[i-1][1][0]%md;
            t[i][2][1]=t[i-1][1][1]%md;
        }
        int res=0;
        for(int j=0;j<=2;j++)
            for(int k=0;k<=1;k++){
                res+=t[n][j][k];
                res%=md;
            }
        return res;
    }
};