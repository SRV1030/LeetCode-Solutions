// https://leetcode.com/problems/employee-importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,Employee*> mp;
    int dfs(int id){
        int s=mp[id]->importance;
        for(auto& i:mp[id]->subordinates) s+=dfs(i);
        return s;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto& i:employees)mp[i->id]=i;
        return dfs(id);
    }
};