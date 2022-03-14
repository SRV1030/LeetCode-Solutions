// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st;
//         for(auto&i:s){
//             bool f=0;
//             while(!st.empty() && i==st.top()) {
//                 st.pop();
//                 f=1;
//             }
//             if(!f) st.push(i);
//         }
//         string ans;
//         while(!st.empty()){
//              ans+=st.top();
//              st.pop();
//          }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        while(i<s.size()-1){
            if(s[i]==s[i+1]){
                int l=i-1,r=i+2;
                for(;l>=0 && r<s.size();l--,r++)
                    if(s[l]!=s[r]) break;
                s=s.substr(0,l+1)+(r<s.size()?s.substr(r):"");
                i= l>=0?0:1;
            }
            else i++;
        }
        return s;
    }
};