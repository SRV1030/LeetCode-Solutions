// https://leetcode.com/problems/complex-number-multiplication

class Solution {
public:    
    vector<int> getNum(string num1){
        vector<int>v(2);
        string s="";
        if(num1[0]!='-'){            
            for(int i=0;num1[i]!='+';i++)s+=num1[i];
            v[0]=stoi(s);
        }
        else{
            for(int i=1;num1[i]!='+';i++)s+=num1[i];
            v[0]= -1*stoi(s);
        }
        int n=s.size();
        s="";
        if(num1[n+1]!='-'){
             for(int i=n+1;num1[i]!='i';i++)s+=num1[i];
             v[1]=stoi(s);
        }
        else{
             for(int i=n+2;num1[i]!='i';i++)s+=num1[i];
            v[1]= -1*stoi(s);
        }
        return v;
        
    }
    string complexNumberMultiply(string num1, string num2) {
        vector<int> r1=getNum(num1);
        vector<int> r2=getNum(num2);
        int r=r1[0]*r2[0]-r1[1]*r2[1];
        int i=r1[0]*r2[1]+r1[1]*r2[0];
        string s="";
        s+=to_string(r);
        s+="+";
        s+=to_string(i);
        s+="i";
        return s;
    }
};