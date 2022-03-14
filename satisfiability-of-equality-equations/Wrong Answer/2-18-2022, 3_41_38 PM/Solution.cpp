// https://leetcode.com/problems/satisfiability-of-equality-equations

class Solution {
public:
    vector<int>p;
    int get_parent(int x){
        if(p[x]==x) return x;
        return p[x]=get_parent(p[x]);
    }
    void get_union(int x,int y){
        p[get_parent(x)]=get_parent(y);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;p.emplace_back(i++));
        for(auto&i:equations){
            int x=i[0]-'a',y=i[3]-'a';
            string v;
            v+=i[1];
            v+=i[2];
            if(v=="==")get_union(x,y);
            else if(get_parent(x)==get_parent(y)) return false;
        }
        return true;
    }
};