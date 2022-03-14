// https://leetcode.com/problems/fraction-addition-and-subtraction

class Solution {
public:
    string fractionAddition(string exp) {
        int n=0,d=1,nt=0,dt=0,i=0;
        while(i<exp.length()){
            if(exp[i]=='-'){
                nt=0,dt=0;
                i++;
                while(exp[i]!='/'){
                    nt=nt*10+exp[i]-'0';
                    i++;
                }
                i++;
                while(i<exp.size() && exp[i]!='-' && exp[i]!='+'){
                    dt=dt*10+exp[i]-'0';
                    i++;
                }
                n=n*dt-nt*d,d=d*dt;
            }        
            else{
               if(exp[i]=='+')i++; 
                nt=0,dt=0;
                    while(exp[i]!='/'){
                        nt=nt*10+exp[i]-'0';
                        i++;
                    }
                    i++;
                    while(i<exp.size() && exp[i]!='-' && exp[i]!='+'){
                        dt=dt*10+exp[i]-'0';
                        i++;
                    }
                    n=n*dt+nt*d,d=d*dt;
            }
        }
        // cout<<n<<" "<<d<<" ";
        for(int j=2;j*j<=abs(n) && j*j<=d;j++)
            while(n%j==0 && d%j==0){
                n=n/j;
                d=d/j;
            }
        if(n==0)d=1;
        return to_string(n)+"/"+to_string(d);
    }
};