// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& a) {
        if(a.size()==1) return 1;
        int i=1,j=a.size()-1,s1=a[0],s2=a[j];
        j-=1;
        while(i<j){            
            if(s1>s2)s2+=a[j--];
            else if(s1<s2)s1+=a[i++];  
            if(s1==s2) return i;
        }
        return -1;      
        
    }
};