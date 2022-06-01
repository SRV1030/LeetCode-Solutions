class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {       
        int c=0;
        for(int i=0;i<size(arr)-m+1;++i){
            vector<int>tmp(arr.begin()+i, arr.begin()+m+i);  
            int tc = 0; 
            for(int j=i;j<size(arr)-m+1;j+=m){
                 vector<int>t(arr.begin()+j, arr.begin()+m+j);
                if(tmp==t)tc++;
                else break;
            }
            c=max(c,tc);
            if(c>=k) return true;
        }
        return c>=k;
    }
};