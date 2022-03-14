// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing

class Solution
{
public:
    int lis(std::vector<int> &a)
    {

        if (a.size() == 0)
            return 0;

        vector<int> b;

        b.push_back(a[0]);

        for (int i = 1; i < a.size(); i++)
        {

            if (b.back() <= a[i])
                b.push_back(a[i]);

            else
            {

                int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();

                b[idx] = a[i];
            }
        }

        return b.size();
    }
    int kIncreasing(vector<int> &a, int k)
    {
        int cost = 0, n = a.size();

        for (int i = 0; i < k; i++)
        {

            vector<int> b;

            for (int j = i; j < n; j += k)
            {

                b.push_back(a[j]);
            }

            cost += b.size() - lis(b);
        }

        return cost;
    }
};