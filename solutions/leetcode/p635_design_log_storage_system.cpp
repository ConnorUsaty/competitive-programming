class LogSystem {
private:
    std::multimap<uint64_t, int> logs_;
    
    uint64_t get_int_timestamp(const std::string& s, int granularity = 5, bool end = false) {
        std::vector<uint64_t> times;
        std::istringstream iss(s);
        std::string time;
        while(std::getline(iss, time, ':')) {
            times.emplace_back(static_cast<uint64_t>(stoi(time)));
        }
        
        if (granularity < 5) times[5] = end ? 59UL : 0UL;
        if (granularity < 4) times[4] = end ? 59UL : 0UL;
        if (granularity < 3) times[3] = end ? 23UL : 0UL;
        if (granularity < 2) times[2] = end ? 31UL : 1UL;
        if (granularity < 1) times[1] = end ? 12UL : 1UL;
        
        uint64_t timestamp = 0;
        timestamp += (times[0] - 1999UL) * 12 * 31 * 24 * 60 * 60;
        timestamp += (times[1] - 1UL) * 31 * 24 * 60 * 60;
        timestamp += (times[2] - 1UL) * 24 * 60 * 60;
        timestamp += times[3] * 60UL * 60;
        timestamp += times[4] * 60UL;
        timestamp += times[5];
        
        return timestamp;
    }
    
public:
    void put(int id, string timestamp) {
        uint64_t time_int = get_int_timestamp(timestamp);
        logs_.insert({time_int, id}); 
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int gran_level = 5;
        if (granularity == "Year") gran_level = 0;
        else if (granularity == "Month") gran_level = 1;
        else if (granularity == "Day") gran_level = 2;
        else if (granularity == "Hour") gran_level = 3;
        else if (granularity == "Minute") gran_level = 4;
        
        uint64_t start_time = get_int_timestamp(start, gran_level, false);
        uint64_t end_time = get_int_timestamp(end, gran_level, true);
        
        vector<int> ids;
        auto it = logs_.lower_bound(start_time);
        while(it != logs_.end() && it->first <= end_time) {
            ids.push_back(it->second);
            it = std::next(it);
        }
        
        return ids;
    }
};

// even with uint64_t have to be cognizant of overflows
// each mult offset for building the integer timeset has to build off the prev, i.e. min mult = 60, hour mult = 3600
// can build a split function easily with std::istringstream and std::getline(iss, token, delim);
// can use std::stoi to convert std::string to int
// VERY IMPORTANT NOTE: can only convert to int, it will throw std::out_of_range if value excees the range of an int
// so it is important to know how to make our own parse_int() with isdigit()