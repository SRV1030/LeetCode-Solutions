class Solution {
public:
    string reformatNumber(string number) {
      string dgs,ans;
        for(auto&i:number)if(isdigit(i))dgs+=i;
        int c=0,i=0,n=dgs.size();
        if(n<=3) return dgs;
        int r=dgs.size()%3==1?4:dgs.size()%3;
        for(i;i<n-r;i++){
            ans+=dgs[i];
            c++;
            if(c==3){
                ans+="-";
                c=0;
            }
        }
        if(r==0){
            ans.pop_back();
        }
        else if(r==2){
            ans+=dgs[n-2];
            ans+=dgs[n-1];
        }
        else{
            c=0;
            for(int i=4;i>=1;i--){
                ans+=dgs[n-i];
                c++;
                if(c==2){
                    ans+="-";
                    c=0;
                }
            }
            ans.pop_back();
        }
        return ans;
    }
};