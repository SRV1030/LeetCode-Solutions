// https://leetcode.com/problems/lucky-numbers-in-a-matrix

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int max = INT_MIN, pos = i;
            for (int  k = 0; k < matrix.size(); k++)
                if (matrix[k][i] > max)
                {
                    max = matrix[k][i];
                    pos = k;
                }
            int min = max;
            int j = 0;
            for (;j < matrix[pos].size(); j++)
                if (min > matrix[pos][j]) break;
            if (j == matrix[pos].size()) ans.push_back(min);
        }
        return ans;
    }
};