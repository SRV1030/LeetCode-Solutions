// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>me,mo;
        int te=0,to=0;
        for(int i=0;i<nums.size();i++){
            if(i&1)mo[nums[i]]++,to++;
            else me[nums[i]]++,te++;
        }
        int fe=0,fec=0,se=0,sec=0,fo=0,foc=0,so=0,soc=0;
        for(auto&[k,v]:me){
            if(v>fec){
                sec=fec;
                se=fe;
                fe=k;
                fec=v;
            }
            else if(v>sec){
                sec=v;
                se=k;
            }
        }
        for(auto&[k,v]:mo){
            if(v>foc){
                soc=foc;
                so=fo;
                fo=k;
                foc=v;
            }
            else if(v>soc){
                soc=v;
                so=k;
            }
        }
        int oe=0,oo=0;
        oe+=(te-fec);
        if(fe!=fo) oe+=(to-foc);
        else oe+=(to-soc);
        oo+=(to-foc);
        if(fe!=fo) oo+=(te-fec);
        else oo+=(te-sec);
        return min(oo,oe);
    }
};