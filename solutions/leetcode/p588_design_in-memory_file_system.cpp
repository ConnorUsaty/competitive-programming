struct FolderNode {
    map<string, FolderNode*> files_{};
    string name_{};
    string content_{};
    bool is_file_ = false;

    void set_name(string& name) {
        name_ = name;
    }

    void set_file() {
        is_file_ = true;
    }

    FolderNode() {}
};

class FileSystem {
private:
    FolderNode* root_;

    FolderNode* traverse(string& path) {
        int idx = 0;
        FolderNode* f = root_;
        while(idx<path.size()){
            string dir = "";
            while(idx<path.size() && path[idx]!='/'){
                dir += path[idx];
                idx++;
            }
            if(dir != ""){
                f = f->files_[dir];
            }
            idx++;
        }
        return f;
    }

    FolderNode* traverse_and_make(string& path, bool file) {
        int idx = 0;
        FolderNode* f = root_;
        while(idx<path.size()){
            string dir = "";
            while(idx<path.size() && path[idx]!='/'){
                dir += path[idx];
                idx++;
            }
            if(dir != ""){
                if(f->files_.find(dir) == f->files_.end()){
                    FolderNode* t = new FolderNode;
                    f->files_.insert({dir, t});
                }
                f = f->files_[dir];
                f->set_name(dir);
            }
            idx++;
        }

        if(file) f->set_file();
        return f;
    }

public:
    FileSystem() {
        root_ = new FolderNode();
    }
    
    vector<string> ls(string path) {
        FolderNode* f = traverse(path);

        if(f->is_file_) {
            return vector<string>{f->name_};
        }
        
        vector<string> res;
        for(auto& it : f->files_){
            res.push_back(it.first);
        }
        return res;
    }
    
    void mkdir(string path) {
        traverse_and_make(path, false);
    }
    
    void addContentToFile(string filePath, string content) {
        FolderNode* f = traverse_and_make(filePath, true);
        f->content_ += content;
    }
    
    string readContentFromFile(string filePath) {
        FolderNode* f = traverse(filePath);
        return f->content_;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */