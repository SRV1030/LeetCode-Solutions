/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int i=0,j=0;
        while(i<m && j<n && head){
            for(int k=j;k<n && head;++k){
                ans[i][k]=head->val;
                head=head->next;
            }
            ++i;
            for(int k=i;k<m && head;++k){
                ans[k][n-1]=head->val;
                head=head->next;
            }
            --n;
            if(i<m){
                for(int k=n-1;k>=j && head;--k){
                    ans[m-1][k]=head->val;
                    head=head->next;
                }
                --m;
            }
            if(j<n){
                for(int k=m-1;k>=i && head;--k){
                    ans[k][j]=head->val;
                    head=head->next;
                }
                ++j;
            }
        }
        return ans;
    }
};