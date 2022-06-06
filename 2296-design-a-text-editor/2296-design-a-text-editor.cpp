class TextEditor {
public:
    string bf,af;
    TextEditor() {
        
    }
    
    void addText(string text) {
        bf+=text;
    }
    
    int deleteText(int k) {
        k=min(k,(int)size(bf));
        bf.resize(size(bf)-k);
        return k;
    }
    
    string cursorLeft(int k) {
        while(!bf.empty() && k--){
            af.push_back(bf.back());
            bf.pop_back();
        }
        return bf.substr(size(bf)-min(10,(int)size(bf)));
    }
    
    string cursorRight(int k) {
        while(!af.empty() && k--){
            bf.push_back(af.back());
            af.pop_back();
        }
        return bf.substr(size(bf)-min(10,(int)size(bf)));
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */