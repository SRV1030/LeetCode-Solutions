// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> fmap;
        for(int i=0;i<n ;i++ ){
            char ch = s[i];
            fmap[ch]++;
        }//TC= O(nlogn)
        
        
        vector<pair<char,int>> ans1(fmap.begin(),fmap.end());//put in vector<pair<char,int>>//TC = O(n)
        sort(ans1.begin(),ans1.end(),[]( const pair<char,int> &a,const  pair<char,int> &b){
            return a.second > b.second;
        });// TC =O(nlogn)
        
        string ans = ""; //SC = O(N)
        for(auto i:ans1){
            for(int j=0;j<i.second;j++){
                ans.push_back(i.first);
            }
        }//TC =O(n)
        
        return ans;
    }
};