// https://leetcode.com/problems/compare-version-numbers

class Solution {
public:
    int compareVersion(string v1, string v2) {
        v1+=".n";
        v2+=".n";
        stringstream vs1(v1),vs2(v2);
        string n1,n2;
        getline(vs1,n1,'.');getline(vs2,n2,'.');
        while(n1!="n" || n2 !="n"){
            cout<<n1<<" "<<n2<<" ";
            if(n1=="n"){
                int x=stoi(n2);
                if(x!=0) return-1;
                getline(vs2,n2,'.');
                while(n2!="n"){
                    int x=stoi(n2);
                    if(x!=0) return-1;
                    getline(vs2,n2,'.');
                }
                return 0;
            }
            else if(n2=="n"){
                int x=stoi(n1);
                if(x!=0) return 1;
                getline(vs1,n1,'.');
                while(n1!="n"){
                    int x=stoi(n1);
                    if(x!=0) return 1;
                    getline(vs1,n1,'.');
                }
                return 0;
            } 
            int x=stoi(n1),y=stoi(n2);
            if(x==y){
                getline(vs1,n1,'.');getline(vs2,n2,'.');
            }
            else return x>y?1:-1;
        }
        return 0;
    }
};