class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st({nums.begin(),nums.end()});
        int longest=0;
        for(int num:st){
            if(!st.count(num-1)){
                int curr=1;
                int curr_num = num;
                while(st.count(curr_num+1)){
                    curr++;
                    curr_num++;
                }
                
                longest = max(curr,longest);
            }  
        }
       return longest;    
    }
};