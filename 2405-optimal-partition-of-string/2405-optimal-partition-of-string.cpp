// class Solution {
// public:
//     int partitionString(string s) {
//         set<char>st,ste;
//         int c=1;
//         for(auto&i:s){
//             if(!st.insert(i).second){
//                 st=ste;
//                 st.insert(i);
//                 ++c;
//             }
//         }
//         return c;
//     }
// };

class Solution {
public:
    int flag=0;
    bool checkbit(int a){
        return flag&(1<<a);
    }
    void setbit(int a){
        flag|=(1<<a);
    }
    int partitionString(string s) {
        int c=1;
        for(auto&i:s){
            int b=i-'a';
            if(checkbit(b)){
                flag=0;
                ++c;
            }
            setbit(b);
        }
        return c;
    }
};