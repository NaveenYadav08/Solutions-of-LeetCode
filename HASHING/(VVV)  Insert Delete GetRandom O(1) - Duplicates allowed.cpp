// leetcode - https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
  unordered_map<int,unordered_set<int>> table;
  vector<int>v;
  
  bool insert(int val) {
    bool flag = true;
    if(table.count(val)) flag = false; 
    table[val].insert(v.size());
    v.push_back(val);
    
    return flag;
  }
    
  bool remove(int val) {
    if(!table.count(val)) return false;
    
    if(val != v.back()){
      int index = *(table[val].begin());
      v[index] = v.back();
      table[v.back()].erase(v.size()-1);
      table[v.back()].insert(index);
      table[val].erase(index);
    }
    else table[val].erase(v.size()-1);
    
    v.pop_back();
    if(table[val].empty()) table.erase(val);
    
    return true;
  }
    
  int getRandom() {
     return v[rand()%v.size()];   
  }
};
