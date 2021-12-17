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



// ["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
// [[], [1], [1], [2], [], [1], []]

// in this example 
// 1 ->   0 , 1
// 2  ->  2
  
//   vector< 1, 1, 2 >
// so remove(1) 
//   as 1 is not the last element inserted
//   so index = 0;
// v[0] = v.back() = 2;
// vector<2,1,2>
// table[2] sae erase v.size()-1 i.e  2 -> empty();
// then table[2] insert(index)  2 -> 0
  
//   table[1].erase( 0 )  1 -> 1
  
  
//   so after this 
//   vector< 2, 1 >
//   1 - > 1
//   2 - > 0
  
  
