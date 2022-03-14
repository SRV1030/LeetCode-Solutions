// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
    bool isEnd;
    Trie *children[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd=false;
        for(int i=0;i<26;i++)children[i]=nullptr;
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *cur=this;
        for(auto c:word){            
            if(!cur->children[c-'a'])cur->children[c-'a']=new Trie;
            cur=cur->children[c-'a'];
        }
        cur->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *cur=this;
        for(auto c:word){
            cur=cur->children[c-'a'];
            if(!cur) return false;
        }
        return cur->isEnd;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *cur=this;
        for(auto c:prefix){
            cur=cur->children[c-'a'];
            if(!cur) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */