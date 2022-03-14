// https://leetcode.com/problems/sorting-the-sentence

class Solution {
public:
    string sortSentence(string s) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>pq;
        stringstream str(s);
        string w,ans;
        while(str>>w){
            int v=w[w.size()-1]-'0';
            w.pop_back();
            pq.push({v,w});
        }
        while(!pq.empty()){
            ans+=pq.top().second+" ";
            pq.pop();
        }
        ans.pop_back();
        return ans;
    }
};