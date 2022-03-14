// https://leetcode.com/problems/design-bitset

class Bitset {
public:
    string v;
    int c0=0,c1=0,size;
    Bitset(int sz) {
        string s(sz,'0');
        v=s;
        c0=sz;
        size=sz;
        // cout<<s
    }
    
    void fix(int idx) {
        if(v[idx]!='1'){
            v[idx]='1';
            c1++;
            c0--;
        }
    }
    
    void unfix(int idx) {
        if(v[idx]=='1'){
            c1--;
            c0++;
            v[idx]='0';
        }
    }
    
    void flip() {
        for(auto&i:v){
            if(i=='1')i='0';
            else if(i=='0')i='1';
        }
        swap(c0,c1);
    }
    
    bool all() {
        return c1==size;
    }
    
    bool one() {
        return c1!=0;
    }
    
    int count() {
        return c1;
    }
    
    string toString() {
        return v;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */