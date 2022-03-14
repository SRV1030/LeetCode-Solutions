// https://leetcode.com/problems/smallest-value-of-the-rearranged-number

class Solution {
public:
    long long smallestNumber(long long num) {
        string ans;
        int f=0;
        if(num<0){f=1;num=-1*num;}
        while(num!=0){
            ans+=to_string(num%10);
            num=num/10;
            // cout<<ans<<endl;;
        }
        sort(ans.begin(),ans.end());
        if(f==1){
            reverse(ans.begin(),ans.end());
        }
        if(ans[0]=='0'){
            int i=0,j=0;
            while(j<ans.size()){
                if(ans[j]!='0'){
                    swap(ans[j],ans[i]);
                    break;
                }
                j++;
            }
        }
        long long n=0;
        for(int i=0;i<ans.size();i++){
            n=n*10+ans[i]-'0';
        }
        return (f==1)?-1*n:n;
    }
};