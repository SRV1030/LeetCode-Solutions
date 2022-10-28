class Solution {
public:
    int rev(int i){
        int ans=0;
        while(i){
            ans=ans*10+i%10;
            i/=10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
      for(int i=num/2;i<=num;++i)if(i+rev(i)==num) return true;
        return false;
    }
};