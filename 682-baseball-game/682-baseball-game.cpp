class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int ans=0;
        for(auto&i:ops){
            if(i=="+"){
                int a=s.top();
                s.pop();
                int b=a+s.top();
                s.push(a);
                s.push(b);
            }
            else if(i=="D") s.push(2*s.top());
            else if(i=="C")s.pop();
            else s.push(stoi(i));
            
        }
        while(!s.empty()) {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};