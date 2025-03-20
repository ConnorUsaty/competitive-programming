class TextEditor {
private:
    string ltext;
    string rtext;
    
public:
    TextEditor() {
        ltext = "";
        rtext = "";
    }
    
    void addText(string text) {
        ltext += text;
    }
    
    int deleteText(int k) {
        k = min(k, (int)ltext.size());
        for(int i=0; i<k; ++i){
            ltext.pop_back();
        }
        return k;
    }
    
    string cursorLeft(int k) {
        k = min(k, (int)ltext.size());
        for(int i=0; i<k; ++i){
            rtext.push_back(ltext.back());
            ltext.pop_back();
        }
        int start = max(0, (int)ltext.size()-10);
        int len = min(10, (int)ltext.size());
        return ltext.substr(start, len);
    }
    
    string cursorRight(int k) {
        k = min(k, (int)rtext.size());
        for(int i=0; i<k; ++i){
            ltext.push_back(rtext.back());
            rtext.pop_back();
        }
        int start = max(0, (int)ltext.size()-10);
        int len = min(10, (int)ltext.size());
        return ltext.substr(start, len);
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