class Solution {
public:
    string addBinary(string a, string b) {
        int j=b.size()-1,i=a.size()-1,c1=0,c2=0,c=0;
        string ans;
        while(i>=0 || j>=0 ||c){
            if(i>=0 && a[i]=='1')c1=1;
            if(j>=0 && b[j]=='1')c2=1;
            if(c^c1^c2)ans.insert(ans.begin(),'1');
            else ans.insert(ans.begin(),'0');
            c=(c1&&c2)||(c2&&c)||(c&&c1);
            c1=0;c2=0;
            i--;j--;
        }
        return ans;
    }
};