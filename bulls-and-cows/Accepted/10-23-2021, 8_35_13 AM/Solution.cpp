// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>v(10),xt;
        for(auto&i:secret)v[i-'0']++;
        int a=0,b=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                a++;
                --v[secret[i]-'0'];
            }
            else xt.push_back(i);
        }
        for(auto& i:xt){
            if(v[guess[i]-'0']>0){
                b++;
                --v[guess[i]-'0'];
            }
        }
        string ans=to_string(a)+'A'+to_string(b)+'B';
        return ans;
    }
};

// class Solution {
// public:
//     string getHint(string secret, string guess) {
//         unsigned int unmatchingSecret[10] = { 0 };
//         unsigned int unmatchingGuess[10] = { 0 };
//         int cows = 0, bulls = 0;
        
//         for (int i = 0; i < secret.size(); i++) {
//             // Found a match Increment Bulls
//             if (secret[i] == guess[i]) {
//                 bulls++;
//             } else {
//                 // Handle Update Cow Cases
//                 if (unmatchingSecret[guess[i] - '0'] > 0) {
//                     // Guess char found in secret map, decrement its count in Secret Map, increment cows
//                     unmatchingSecret[guess[i] - '0']--;
//                     cows++;
//                 } else {
//                     // Not found, increment Guess char count in Guess MaP
//                     unmatchingGuess[guess[i] - '0']++; 
//                 }
//                 if (unmatchingGuess[secret[i] - '0'] > 0) {
//                     // Secret char found in Guess Map, decrement its count in Guess Map, increment cows
//                     unmatchingGuess[secret[i] - '0']--;
//                     cows++;
//                 } else {
//                     // Not found, update Secret char count in Secret Map
//                     unmatchingSecret[secret[i] - '0']++;
//                 }
//             }
//         }
        
//         return to_string(bulls) + "A" + to_string(cows) + "B";
//     }
// };