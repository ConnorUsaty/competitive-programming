struct FileNode {
    unordered_map<string, FileNode*> files_{};
    int val_{};

    void set_val(int val) {
        val_ = val;
    }

    FileNode() {}
};

class FileSystem {
private:
    FileNode* root_;

    vector<string> parse_path(string& path) {
        vector<string> res;
        int i = 0;
        while(i<path.size()){
            while(i<path.size() && path[i]=='/') i++;

            string dir = "";
            while(i<path.size() && path[i]>='a' && path[i]<='z') {
                dir += path[i];
                i++;
            }
            if(dir != "") {
                res.push_back(dir);
            }
        }
        return res;
    }

public:
    FileSystem() {
        root_ = new FileNode();
    }
    
    bool createPath(string path, int value) {
        vector<string> dirs = parse_path(path);
        FileNode* f = root_;

        // traverse parent path
        for(int i=0; i<dirs.size()-1; ++i) {
            if(f->files_.find(dirs[i]) == f->files_.end()) {
                return false;
            }
            f = f->files_[dirs[i]];
        }

        // check for file, create and set val if not exist
        if(f->files_.find(dirs.back()) == f->files_.end()){
            FileNode* t = new FileNode();
            t->set_val(value);
            f->files_.insert({dirs.back(), t});
            return true;
        }
        return false;
    }
    
    int get(string path) {
        vector<string> dirs = parse_path(path);
        FileNode* f = root_;
        // traverse path
        for(int i=0; i<dirs.size(); ++i) {
            if(f->files_.find(dirs[i]) == f->files_.end()) {
                return -1;
            }
            f = f->files_[dirs[i]];
        }
        return f->val_;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */