class Solution {
public:
    vector<int> evenOddBit(int n) {
        int o=0,e=0;
        for(int i=0;i<32;++i){
            if(n&(1<<i)){
                if(i&1)++o;
                else ++e;
            }
        }
        return {e,o};
    }
};