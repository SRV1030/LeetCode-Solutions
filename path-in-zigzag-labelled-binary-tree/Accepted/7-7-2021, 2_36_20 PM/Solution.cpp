// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> v;
        v.push_back(label);
        while(label>1){
            int t=label,p=0;
            while(t>1){
                t/=2;
                p++;
            }
            t=label-pow(2,p);
            label-=(t+t/2+1);
            v.push_back(label);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};