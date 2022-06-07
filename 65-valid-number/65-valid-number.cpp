class Solution {
public:
    bool isNumber(string s) {
        ios::sync_with_stdio(false);
        
        bool sign = false, eorE = false, decimal =false, result = true;
        int size = s.size();
        
        switch(s[0]){
            case '+' : 
                if(size == 1) return false;
                sign = true;
                break;
            case '-' :
                if(size == 1) return false;
                sign = true;
                break;
            case 'e':
                return false;
                break;
            case 'E' :
                return false;
                break;
            case '.' :
                if(size == 1) return false;
                decimal = true;
                break;
            case '0' ... '9' : break;
            default : return false;
        }
        
        for(int i=1; i<size; i++){
            switch(s[i]){
                case '+' : 
                    if(i==size-1) return false;
                    if(s[i-1] == 'e' || s[i-1] == 'E') break;
                    else return false;
                case '-' : 
                    if(i==size-1) return false;
                    if(s[i-1] == 'e' || s[i-1] == 'E') break;
                    else return false;
                case 'e':
                    if(eorE || i==size-1 || s[i-1]=='+' || s[i-1]=='-' || (s[i-1]=='.' && i==1) ) return false;
                    eorE = true;
                    break;
                case 'E' :
                    if(eorE || i==size-1 || s[i-1]=='+' || s[i-1]=='-' || (s[i-1]=='.' && i==1) ) return false;
                    eorE = true;
                    break;
                case '.' :
                    if(decimal || eorE || ( (s[i-1]=='+'||s[i-1]=='-') && i==size-1) ) return false;
                    decimal = true;
                    break;
                case '0' ... '9' : break;
                default : return false;
            }
        }
        
        return result;
    }
};