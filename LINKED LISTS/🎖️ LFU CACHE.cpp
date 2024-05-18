// in clash of freq del least recent one

class LFUCache {
    
    int minFreq = INT_MAX;
    int capacity;
    unordered_map<int, pair<int, int>> m; // key -> {value, freq}
    unordered_map<int, list<int>> freq;   // freq -> list of keys
    unordered_map<int, list<int>::iterator> pos; // key -> position in freq list/Node

    public:
    LFUCache(int capcity) {capacity=capcity;}

    int get(int key) {
        if (m.find(key) == m.end()) return -1; // not exist
        // auto Node = pos[key];
        freq[m[key].second].erase(pos[key]); // erase the Node from its freq list
        m[key].second++; // update frq
        freq[m[key].second].push_back(key); // push in new frqList
        pos[key] = --freq[m[key].second].end(); // beacuase the end points to one element after that
        if (freq[minFreq].size() == 0) minFreq++; // ?
        return m[key].first;
    }

    void put(int key, int value) {
        // if (capacity <= 0) return;
        if (get(key) != -1) { // if present update the value
            m[key].first = value;
            return;
        }
        if (m.size() >= capacity) { // is size > capacity // del the LFU
            int k = freq[minFreq].front(); // LRU in the frq list
            freq[minFreq].pop_front();
            pos.erase(k);
            m.erase(k);
        }
        
        m[key] = {value, 1};
        freq[1].push_back(key);
        pos[key] = --freq[1].end();
        minFreq = 1;
    }

};


