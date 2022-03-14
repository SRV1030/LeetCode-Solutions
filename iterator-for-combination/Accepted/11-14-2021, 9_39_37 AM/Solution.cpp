// https://leetcode.com/problems/iterator-for-combination

class CombinationIterator {
public:vector<string>comb;
    int ind=0;
    void fillComb(string &c,int &mxl,string t,int i){
        if(t.size()==mxl) comb.push_back(t);
        else if(i>=c.size()) return;
        else{
            for(int j=i;j<c.size();j++){                
                t+=c[j];
                fillComb(c,mxl,t,j+1);
                t.pop_back();
            }
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        string t;
        fillComb(characters,combinationLength,t,0);
    }
    
    string next() {
        if(hasNext()) return comb[ind++];
        return "";
    }
    
    bool hasNext() {
        return ind<comb.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */