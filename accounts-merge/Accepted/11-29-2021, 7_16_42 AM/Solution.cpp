// https://leetcode.com/problems/accounts-merge

class Solution {
public:

    unordered_map<string, unordered_set<string>> adjList; // Using set will eliminate same emails
    unordered_map<string, string> email_to_name;
    unordered_map<string, bool> visited;
    
    void BFS(string email, vector<vector<string>> &res) {
        visited[email] = true;    
        queue<string> q;
        q.push(email);
        
        // Each connected components group are stored here;
        vector<string> connectedEmails;
        // First Value is always the name 
        connectedEmails.push_back(email_to_name[email]);
        
        // Regular BFS
        while(!q.empty()) {
            email = q.front();
            q.pop();
            connectedEmails.push_back(email);
            
            for(auto newEmail: adjList[email]){
                if(!visited[newEmail]) {
                    visited[newEmail] = true;
                    q.push(newEmail);
                }
            }
        }
        // Sort the emails, but remember first value was name, dont sort that too.
        sort(connectedEmails.begin()+1, connectedEmails.end());
        res.push_back(connectedEmails);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Building Graph
        for(auto account: accounts) {
            string name = account[0];
            for(int i=1; i<account.size(); i++) {
                email_to_name[account[i]] = name;
                visited[account[i]] = false;
                for(int j=1; j<account.size(); j++) { 
                    adjList[account[i]].insert(account[j]);
                    adjList[account[j]].insert(account[i]);
                }
            }
        }
        
         vector<vector<string>> res;
        
        // Checking for all Components of graph
        for(auto email: adjList) {
            if(!visited[email.first]) {
                BFS(email.first, res);
            }
        }
       
        return res;
    }
};