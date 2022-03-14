// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     priority_queue<pair<int,int>>pq;
    //     for(int i=0;i<k;i++)pq.push({abs(arr[i]-x),arr[i]});
    //     for(int i=k;i<arr.size();i++){
    //         int v=abs(arr[i]-x);
    //         if(v<pq.top().first){
    //             pq.pop();
    //             pq.push({v,arr[i]});
    //         }
    //     }   
    //     vector<int> ans;
    //     while(!pq.empty()){
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n=arr.size(),lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(lb==n)lb--;
        vector<int> res;
        if(x==arr[lb] || lb==0) res.push_back(arr[lb]);
        else{
            if(abs(arr[lb]-x)<abs(arr[lb-1]-x)) res.push_back(arr[lb]);
            else res.push_back(arr[lb--]);
        }
        int l=lb-1,r=lb+1;
        k--;
        while(k && l>=0 && r<n){
            if(abs(arr[l]-x)<=abs(arr[r]-x))res.push_back(arr[l--]);
            else res.push_back(arr[r++]);
            k--;
        }
        while(k && l>=0){
            res.push_back(arr[l--]);
            k--;
        }
        while(k && r<n){
            res.push_back(arr[r++]);
            k--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};