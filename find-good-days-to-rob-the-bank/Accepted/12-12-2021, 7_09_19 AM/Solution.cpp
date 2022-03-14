// https://leetcode.com/problems/find-good-days-to-rob-the-bank

class Solution {
public:
    vector<int>left,right;

    void preprocess(vector<int> arr, int N){
        left[0] = 0;
        int lastIncr = 0; 
        for (int i = 1; i < N; i++){
            if (arr[i] <= arr[i - 1])lastIncr++;
            else lastIncr=0;
            left[i] = lastIncr;
        }        
        right[N - 1] = 0;
        int firstDecr = 0; 
        for (int i = N - 2; i >= 0; i--){
            if (arr[i] <= arr[i + 1])
                firstDecr ++;
            else firstDecr=0;
            right[i] = firstDecr;
        }
    }    
 
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>ans;
        if(time==0) {
            for(int i=0;i<security.size();i++)ans.push_back(i);
            return ans;
        }
        int n=security.size();
        left=vector<int>(n);
        right=vector<int>(n);
        preprocess(security,n);
        for(int i=time;i<n-time;i++){      
            // cout<<left[i]<<" "<<right[i]<<" "<<security[i]<<" "<<i<<"\n";
            if(left[i]>=time && right[i]>=time)ans.push_back(i);
        }
        return ans;
    }
};