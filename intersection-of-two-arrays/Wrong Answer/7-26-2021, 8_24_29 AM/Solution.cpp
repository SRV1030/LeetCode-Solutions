// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        vector<int> v;
        int s1=n1.size(),s2=n2.size(),i=0,j=0;
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        while(i<s1 && j<s2){
            if(n1[i]>n2[j])j++;
            else if(n2[j]>n1[i])i++;
            else{
                v.push_back(n1[i]);
                while(i<s1 && j<s2 && n1[i]==n2[j] ){
                    i++;
                    j++;
                    // if(i>s1 || j>s2) break;
                }
            }
        }
        return v;
    }
};