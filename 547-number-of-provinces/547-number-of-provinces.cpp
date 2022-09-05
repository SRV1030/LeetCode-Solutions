class Solution {
public:
    int n;
    vector<int> parent;
    int get_parent(int i){
        if(i==parent[i]) return i;
        return parent[i]=get_parent(parent[i]);
    }
    void get_union(int i,int j){
        parent[get_parent(i)]=get_parent(j);
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        n=isCon.size();
        for(int i=0;i<n;parent.emplace_back(i++));
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) if(isCon[i][j]) get_union(i,j);
        unordered_set<int>st;
        for(auto&i:parent)st.insert(get_parent(i));
        return st.size();
    }
};

// class Solution {
// public:
//     int n;
//     void dfs(vector<vector<int>>& isCon,int i){
//         isCon[i][i]=2;
//         for(int j=0;j<n;j++)
//             if(isCon[j][j]==1 && isCon[i][j]==1)dfs(isCon,j);
//     }
//     int findCircleNum(vector<vector<int>>& isCon) {
//         n=isCon.size();
//         int c=0;
//         for(int i=0;i<n;i++){
//             if(isCon[i][i]==1){
//                 dfs(isCon,i);
//                 c++;
//             }
//         }
//         return c;
//     }
// };