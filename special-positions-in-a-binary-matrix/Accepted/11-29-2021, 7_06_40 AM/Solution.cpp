// https://leetcode.com/problems/special-positions-in-a-binary-matrix

class Solution {
public:
    int numSpecial(vector<vector<int>> &mat) {
        const size_t row_Length = mat.size(), col_Length = mat[0].size();
        size_t result(0);
        bool flag(true); // false = there was another 1 in the same column or row, otherwise true

        for (auto column = 0; column < col_Length; column++) {
            for (auto row = 0; row < row_Length; row++) {
                if (mat[row][column] == 1) {
                    for (auto rowCheck = 0; rowCheck < row_Length; rowCheck++) {
                        if (rowCheck != row) {
                            if (mat[rowCheck][column] == 1) {
                                flag = false;
                                break;
                            }
                        }
                    }

                    for (auto columnCheck = 0; columnCheck < col_Length; columnCheck++) {
                        if (columnCheck != column) {
                            if (mat[row][columnCheck] == 1) {
                                flag = false;
                                break;
                            }
                        }
                    }

                    if (flag) {
                        result++;
                    }

                    flag = true;
                }
            }
        }

        return result;
    }
};