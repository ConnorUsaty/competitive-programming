class LFUCache {
    // key: frequency, value: list of original key-value pairs that have the
    // same frequency.
    unordered_map<int, list<pair<int, int>>> frequencies;
    // key: original key, value: pair of frequency and the iterator
    // corresponding key in the frequencies map's list.
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    int capacity;
    int minf;

    void insert(int key, int frequency, int value) {
        frequencies[frequency].push_back({key, value});
        cache[key] = {frequency, --frequencies[frequency].end()};
    }

public:
    LFUCache(int capacity) : capacity(capacity), minf(0) {}

    int get(int key) {
        const auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }
        const int f = it->second.first;
        const auto iter = it->second.second;
        const pair<int, int> kv = *iter;
        frequencies[f].erase(iter);
        if (frequencies[f].empty()) {
            frequencies.erase(f);

            if (minf == f) {
                ++minf;
            }
        }

        insert(key, f + 1, kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        const auto it = cache.find(key);
        if (it != cache.end()) {
            it->second.second->second = value;
            get(key);
            return;
        }
        if (capacity == cache.size()) {
            cache.erase(frequencies[minf].front().first);
            frequencies[minf].pop_front();

            if (frequencies[minf].empty()) {
                frequencies.erase(minf);
            }
        }

        minf = 1;
        insert(key, 1, value);
    }
};

// when O(1) inserts and deletes and updates are required -> HashMap, Linked List
// can use key val where val is the LL iterator so that updates and everything to the LL can be done in a true O(1)
// then the linked list can contain the actual values, such as freq and val, and maintain ordering supporting insert, delete, update, etc. in O(1)
// list.erase(iterator) for when you have an iterator, list.remove(value) when you only have the value
// should be using .erase() when possible instead of .remove() for O(1) removals instead of O(n) from having to find the value within LL before O(1) removal
// .find(), .begin(), .end() all return iterators (pointers), use -> to access members and update. Useful for updating without redoing hash or for storing address
