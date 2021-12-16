// LEETCODE _ https://leetcode.com/problems/design-hashmap/

// // NOOB CODE 
class MyHashMap {
public:
    /** Initialize your data structure here. */
    int um[1000001];
    MyHashMap() {
        memset(um,-1,sizeof(um));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        um[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return um[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        um[key]=-1;
    }
};


// code with chaining

class MyHashMap {
public:
    vector<list<pair<int,int>>> store;
    int size;
    MyHashMap() {
        size=10000;
        store.resize(size);
    }
    
    int hash(int key){      // finding the position of insertion of {key,value} pair
        return key%size;    
    }
    
    list<pair<int,int>> :: iterator search(int key){  // finding the position of {key,value} pair
        int i=hash(key);
        list<pair<int,int>> :: iterator it;
        for(it=store[i].begin();it!=store[i].end();++it){
            if(it->first==key)  return  it;
        }
        return it;
    }
    
    void put(int key, int value) {                    // storing the {key,value} pair
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it!=store[i].end())  it->second=value;
        else store[i].push_back({key,value});
    }
    
    int get(int key) {                                  // getting the value of specific key
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it!=store[i].end()&&it->first==key)  return it->second;
        return -1;
    }
    
    void remove(int key) {                              // removing the {key,value} pair
        int i=hash(key);
        list<pair<int,int>> :: iterator it=search(key);
        if(it!=store[i].end()){
            store[i].erase(it);
            return;
        }  
    }
};
