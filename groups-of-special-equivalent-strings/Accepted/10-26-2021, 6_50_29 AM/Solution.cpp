// https://leetcode.com/problems/groups-of-special-equivalent-strings

// class Solution {
// public:
//     int numSpecialEquivGroups(vector<string>& words) {
//         unordered_map<string,int>mp;
//         for(auto& i:words){            
//             vector<char>e(26),o(26);
//             for(int j=0;j<i.size();j++){
//                 if(j%2)o[i[j]-'a']++;
//                 else e[i[j]-'a']++;
//             }
//             string s;
//             for(int j=0;j<26;j++){
//                 if(o[j]) s+=to_string(o[j])+(char)(j+'a')+'o';
//                 if(e[j]) s+=to_string(e[j])+(char)(j+'a')+'e';
//             }             
//             mp[s]++;
//         }
//         return mp.size();
//     }
// };

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string>mp;
        for(auto& i:words){            
            string s1,s2;
            for(int j=0;j<i.size();++++j)s1+=i[j];
            sort(s1.begin(),s1.end());
            for(int j=1;j<i.size();++++j)s2+=i[j];
            sort(s2.begin(),s2.end());
            mp.insert(s1+s2);
        }
        return mp.size();
    }
};