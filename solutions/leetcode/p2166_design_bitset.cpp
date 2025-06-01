class Bitset {
private:
    std::vector<uint64_t> bits_;
    uint32_t last_;

public:
    Bitset(int size) {
        while(size>0){
            last_ = size;
            size -= 64;
            bits_.push_back(0);
        }
    }
    
    void fix(int idx) {
        uint64_t bits_idx = idx/64;
        uint64_t bit = 63-(idx%64);
        uint64_t b = 1U;
        bits_[bits_idx] |= (b << bit);
    }
    
    void unfix(int idx) {
        uint64_t bits_idx = idx/64;
        uint64_t bit = 63-(idx%64);
        uint64_t b = 1U;
        bits_[bits_idx] &= ~(b << bit);
    }
    
    void flip() {
        for(int i=0; i<(int)bits_.size()-1; ++i){
            bits_[i] ^= (std::numeric_limits<uint64_t>::max());
        }
        uint64_t last = (std::numeric_limits<uint64_t>::max() >> (64-last_)) << (64-last_);
        bits_[(int)bits_.size()-1] ^= last;
    }
    
    bool all() {
        for(int i=0; i<(int)bits_.size()-1; ++i){
            if (bits_[i] != std::numeric_limits<uint64_t>::max()){
                return false;
            }
        }
        uint64_t last = (std::numeric_limits<uint64_t>::max() >> (64-last_)) << (64-last_);
        return (bits_[(int)bits_.size()-1] == last);
    }
    
    bool one() {
        for(int i=0; i<(int)bits_.size(); ++i){
            if (bits_[i] != 0){
                return true;
            }
        }
        return false;
    }
    
    int count() {
        int cnt=0;
        for(int i=0; i<(int)bits_.size(); ++i){
            cnt += __builtin_popcountll(bits_[i]);
        }
        return cnt;
    }
    
    string toString() {
        string ans = "";
        uint64_t b = 1U;
        for(int j=0; j<(int)bits_.size()-1; ++j){
            for(int i=63; i>=0; --i){
                ans.push_back(((bits_[j] >> i) & b) +48);
            }
        }

        for(uint64_t i=0; i<last_; ++i){
            ans.push_back(((bits_[(int)bits_.size()-1] >> (63U-i)) & b) +48);
        }

        return ans;
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


// to zero out last x bits in an n bit type can do >> n-x << n-x
// to clear a specific bit use & ~(1 << bit)
// __builtin_popcount is made for integers, when using larger types use __builtin_popcountll