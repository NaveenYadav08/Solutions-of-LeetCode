// LEETCODE- https://leetcode.com/problems/design-hashset/

// CODE 

// Approach 1: ARRAY Implementation ( NOOB )
class MyHashSet {
private:
	vector<bool> table;
public:
	MyHashSet() : table(1e6 + 1, false) {}
	
	void add(int key) {
		table[key] = true;
	}
	
	void remove(int key) {
		table[key] = false;
	}
	
	bool contains(int key) {
		return table[key];
	}
};

// Complexity

// Time: O(1)
// Space: O(n)


// APPROACH 2 - CHAINING 
class MyHashSet {
public:
    vector<list<int>> store;
    int size;
    MyHashSet() {
        size=100;
        store.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<int> :: iterator search(int key){
        int i=hash(key);
        return find(store[i].begin(),store[i].end(),key);
    }
    
    void add(int key) {
        if(contains(key))   return;
        int i=hash(key);
        store[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))   return;
        int i=hash(key);
        store[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key)!=store[i].end()) return true;
        else return false;
    }
};

// Complexity

// Time: O(n), average O(1)
// Space: O(n)
