// https://leetcode.com/problems/goat-latin

class Solution {
public:
    bool isvowel(char a){
        if(a<='Z')a+=32;
        return a=='o' || a=='a' || a=='u' || a=='e' || a=='i';
    }
    string toGoatLatin(string sentence) {
        sentence+=" \n";
        string ans,t;
        stringstream s(sentence);
        string add="a";
        while(true){
            getline(s,t,' ');
            if(t=="\n") break;
            if(isvowel(t[0]))t+="ma";
            else{
                char x=t[0];
                t.erase(t.begin());
                t.push_back(x);
                t+="ma";
            }
            ans+=t+add+" ";
            add+="a";
        }
        ans.pop_back();
        return ans;
    }
};