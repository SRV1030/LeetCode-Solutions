// https://leetcode.com/problems/maximum-score-from-removing-substrings

class Solution {
public:
    void rem(string &s1,int x,string pt,int &c1){
        if(s1.empty())return;
        else{
            for(int i=0;i<s1.size()-1;i++){
                string t;
                t+=s1[i];
                t+=s1[i+1];
                if(t==pt){
                    if(i==0)s1=s1.substr(2);
                    else s1=s1.substr(0,i)+s1.substr(i+2);
                    // cout<<s1<<" ";
                    c1+=x;
                    rem(s1,x,pt,c1);
                    return;
                }
                
            }
        }
    }
    int maximumGain(string s, int x, int y) {
        string s1=s,s2=s;
        int c1=0,c2=0;
        rem(s1,x,"ab",c1);        
        rem(s1,y,"ba",c1);
        rem(s2,y,"ba",c2);
        rem(s2,x,"ab",c2);
        return max(c1,c2);
    }
};