// https://leetcode.com/problems/design-bitset

class Bitset {
public:
    string v0,v1;
    int c0=0,c1=0,size;
    Bitset(int sz) {
        string s(sz,'0');
        string s1(sz,'1');
        v0=s;
        v1=s1;
        c0=sz;
        size=sz;
        // cout<<s
    }
    
    void fix(int idx) {
        if(v0[idx]!='1'){
            v0[idx]='1';
            c1++;
            c0--;
        }
        if(v1[idx]!='0')
            v1[idx]='0';
    }
    
    void unfix(int idx) {
        if(v0[idx]=='1'){
            c1--;
            c0++;
            v0[idx]='0';
        }
        if(v1[idx]=='0')
            v1[idx]='1';
    }
    
    void flip() {
        swap(v1,v0);
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
        return v0;
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