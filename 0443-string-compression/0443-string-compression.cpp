class Solution {
public:
    int compress(vector<char>& chars) {
        int c=0, r=1;
        for(int i=0;i<chars.size();i++){
            
            if(i<chars.size()-1 && chars[i]==chars[i+1]) r++;
            else{
                chars[c++]=chars[i];
                if(r>1){
                    string s=to_string(r);
                    for(auto i:s)chars[c++]=i;
                    r=1;                    
                }
            }
        }        
        return c;
    }
};