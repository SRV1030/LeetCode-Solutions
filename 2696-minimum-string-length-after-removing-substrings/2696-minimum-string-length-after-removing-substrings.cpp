class Solution {
public:
    int minLength(string s) {
        int f=0;
        while(!f){
            string t;
            f=1;
            for(int i=0;i<size(s);++i){
                if(i<size(s)-1){
                    string x;
                    x+=s[i];
                    x+=s[i+1];
                    // cout<<x<<" ";
                    if(x=="AB"||x=="CD"){
                        i++;
                        f=0;
                        continue;
                    } 
                }
                t+=s[i];
            }
            // cout<<t<<"\n";
            s=t;
        }
        return size(s);
    }
};