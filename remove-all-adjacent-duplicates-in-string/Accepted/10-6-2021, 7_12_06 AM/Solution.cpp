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
    string removeDuplicates(string S) {
        int runner = 0;
        while(runner < ((int)S.size()) - 1){
            if(S[runner] == S[runner + 1]){
                int i = runner - 1, j = runner + 2;
                for(;i >= 0 && j < S.size(); --i, ++j){
                    if(S[i] != S[j]){
                        break;
                    }
                }
                
                S = S.substr(0,i + 1) + (j < S.size() ? S.substr(j) : "");
                runner = i >= 0;
            }else{
                runner++;
            }
            
        }
        
        return S;
    }
    
};