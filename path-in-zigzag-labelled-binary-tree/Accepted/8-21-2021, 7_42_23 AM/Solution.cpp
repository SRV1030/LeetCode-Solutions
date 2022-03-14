// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree

/*
instance :

1. get a number in odd row, like 14->4
we can see 14 as 9, and 9/2 will be 4 as tree's rule.

	a. offset from bound = upper bound of nrow+1 - last picked value = 15 - 14 = 1
	b. in order value = lower bound of nrow+1 + offset from bound = 8 + 1 = 9
	c. value of rnow = in order value / 2
2. get a number in even row, like 4->3
we can see 3 as 2, because 4/2 will be 2. And we need to know in this rule, which value will be at the position of 2 should be.

	a. offset from bound = last picked value / 2 - lower bound of nrow = 4/2 - 2 = 0
	b. in order value = upper bound of nrow - offset from bound = 3 - 0 = 3
*/


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int nrow = 1;
        vector<int> res(1,label);
        while(label >= pow(2,nrow)) 
            nrow++;
        while(--nrow){
            int tmp = 0;
            if(nrow%2) 
                tmp = (pow(2,nrow+1)-1-res.back()+pow(2,nrow))/2;
            else
                tmp = pow(2,nrow)-1-(res.back()/2-pow(2,nrow-1));
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};