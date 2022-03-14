// https://leetcode.com/problems/maximize-the-confusion-of-an-exam

class Solution {
public:
    int maxConsecutiveAnswers(string ak, int k) {
        int mx=INT_MIN,st=0,c=0;
        for(int i=0;i<ak.size();i++){
            if(ak[i]=='F')c++;
            while(c>k){
                if(ak[st]=='F')c--;
                st++;
            }
            mx=max(mx,i-st+1);
        }
        st=0;
        c=0;
        for(int i=0;i<ak.size();i++){
            if(ak[i]=='T')c++;
            while(c>k){
                if(ak[st]=='T')c--;
                st++;
            }
            mx=max(mx,i-st+1);
        }
        return mx;
    }
};