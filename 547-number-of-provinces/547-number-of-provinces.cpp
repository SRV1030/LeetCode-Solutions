class Solution {
public:
    int n;
    vector<int>p;
    int get_p(int i){
        if(p[i]==i) return i;
        return p[i]=get_p(p[i]);
    }
    void _union(int i,int j){
        p[get_p(i)]=get_p(j);
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        n=size(isCon);
        for(int i=0;i<n;p.emplace_back(i++));
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(isCon[i][j])_union(i,j);
        unordered_set<int>st;
        for(auto&i:p)st.insert(get_p(i));
        return size(st);
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