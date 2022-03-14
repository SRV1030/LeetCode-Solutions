// https://leetcode.com/problems/validate-ip-address

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.size()<=15){
            IP+=".n";
            stringstream str(IP);
            string s;
            int c=0;
            getline(str,s,'.');
            while(s!="n"){
                if(s.empty()) return "Neither";
                int v=0;                
                for(auto& i:s){
                    cout<<i<<" ";
                    if(isdigit(i))v=v*10+(i-'0');
                    else return "Neither";
                }
                if((s[0]=='0' && s.size()>1)||v<0 || v>255) return "Neither";
                c++;
                getline(str,s,'.');
            }
            return c==4?"IPv4":"Neither";
        }
        else if(IP.size()<=39){
            IP+=":n";
            stringstream str(IP);
            string s;
            int c=0;
            getline(str,s,':');
            while(s!="n"){
                if(s.length()<1 || s.length()>4) return "Neither";
                for(auto& i:s){
                    if(isdigit(i)||(i>='A' && i<='F')||(i>='a' && i<='f')) continue;
                    else return "Neither";
                }
                c++;
                getline(str,s,':');
            }
            return c==8?"IPv6":"Neither";
        }
        else{           
            return "Neither";
        } 
    }
};