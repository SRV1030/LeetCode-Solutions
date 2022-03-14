// https://leetcode.com/problems/design-add-and-search-words-data-structure

class Trie{
    public:
    bool isEnd;
    Trie* children[26];
    Trie(){
        isEnd=false;
        for(int i=0;i<26;i++)children[i]=NULL;
    }
    
};


class WordDictionary {
public:
    Trie* head;
    WordDictionary() {
        head=new Trie();
    }
    
    void addWord(string word) {
        Trie* t=head;
        for(auto& i:word){
            if(!t->children[i-'a'])t->children[i-'a']=new Trie;
            t=t->children[i-'a'];
        }
        t->isEnd=true;
    }
    bool find(string word,int i, Trie* t){
        if(i==word.size())return t->isEnd;
        if(word[i]=='.'){
            for(int j=0;j<26;j++)
                if(t->children[j] && find(word,i+1,t->children[j])) return true;
        }else{
            if(!t->children[word[i]-'a']) return false;
            return find(word,i+1,t->children[word[i]-'a']);
        }
        return false;
    }
    bool search(string word) {
        Trie* t=head;
        return find(word,0,t);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */