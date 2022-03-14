// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int sd) {
        int st=0,ms1=0,ms2=0,n=nums.size();
        for(int i=0;i<f;i++)ms1+=nums[i];
        int s=ms1,b=0;
        for(int i=f;i<n;i++){
            s=s+nums[i]-nums[b++];
            if(s>ms1){
                ms1=s;
                st=b;
            } 
        }
        int i=0,j=0,t=0;
        while(i<n && j<n){
            if(j==b){
                j+=f+1;
                i=j;
                t=0;
            }
           if(j-i+1==sd){  
                t+=nums[j];
                if(t>ms2)ms2=t;
                t-=nums[i++]; 
                j++;
            }
            else t+=nums[j++];
        }
        cout<<b<<" "<<ms1<<" "<<ms2<<" ";
        return ms1+ms2;
    }
};