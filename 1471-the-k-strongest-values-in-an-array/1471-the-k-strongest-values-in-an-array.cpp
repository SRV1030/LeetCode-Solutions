class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int i=0,j=size(arr)-1;
        sort(begin(arr),end(arr));
        double md=arr[(j)/2];
        while(--k>=0){
            if(md-arr[i]>arr[j]-md)i++;
            else j--;
        }
        arr.erase(begin(arr)+i,begin(arr)+j+1);
        return arr;
    }
};

// class Solution {
// public:
//     struct comparator{
//         bool operator()(pair<double,int> a,pair<double,int> b){
//             if(a.first!=b.first) return a.first>b.first;
//             else return a.second>b.second;
//         }
//     };
//     vector<int> getStrongest(vector<int>& arr, int k) {
//         sort(begin(arr),end(arr));
//         int n=size(arr);
//         double md=arr[(n-1)/2];
//         priority_queue<pair<double,int>,vector<pair<double,int>>,comparator>pq;
//         for(auto&i:arr){
//             pq.push({abs(md-i),i});
//             if(size(pq)>k)pq.pop();
//         }
//         vector<int> ans;
//         while(!pq.empty()){
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
//     }
// };