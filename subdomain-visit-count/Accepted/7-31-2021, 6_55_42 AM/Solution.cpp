// https://leetcode.com/problems/subdomain-visit-count

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(auto i : cp){
            int num,d1=-2,d2=-1;
            for(int j=0;j<i.size();j++){
                if(i[j]==' ')num=j;
                else if(i[j]=='.'){
                    if(d1<0) d1=j;
                    else d2=j;
                }
            }
            int v=stoi(i.substr(0,num));
            string c1,c2;
            if(d2>=0){                
                ans.push_back(i);
                c1=i.substr(d1+1);
                c2=i.substr(d2+1);
            }
            else{
                c1=i.substr(num+1);
                c2=i.substr(d1+1);
            }
             mp[c1]+=v;
             mp[c2]+=v;
            
        }
        for(auto i:mp){
            string t=to_string(i.second);
            t=t+" "+i.first;
            ans.push_back(t);
        }
        return ans;
    }
};