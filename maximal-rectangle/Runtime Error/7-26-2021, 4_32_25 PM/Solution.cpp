// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    vector<int> nsl(vector<int> v){
        vector<int> ans;
        stack<int>st;
        int n=v.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && v[i]<=v[st.top()])st.pop();
            int a=st.empty()?-1:st.top();
            ans.push_back(a);
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int> v){
        vector<int> ans;
        stack<int>st;
        int n=v.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[i]<=v[st.top()])st.pop();
            int a=st.empty()?n+1:st.top();
            ans.push_back(a);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int MAH(vector<int> v){
        vector<int>l=nsl(v);
        vector<int>r=nsr(v);
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans=max(ans,(r[i]-l[i]-1)*v[i]);
        } 
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int r=mat.size(),c=mat[0].size();
        if(r==0) return 0;
        vector<int>v(c);
        for(int i=0;i<c;i++)v[i]=mat[0][i]-'0';
        int mx=MAH(v);
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='0')v[j]=0;
                else v[j]+=mat[0][i]-'0';
            }
            mx=max(mx,MAH(v));
        }
        return mx;
    }
};