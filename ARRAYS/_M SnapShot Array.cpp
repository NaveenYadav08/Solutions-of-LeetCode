//LEETCODE - https://leetcode.com/problems/snapshot-array/

// CODE -

class SnapshotArray {
    unordered_map<int, map<int, int>> A;
    int snap_no = 0;
public:
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        A[index][snap_no] = val;
    }
    
    int snap() {
        return snap_no++;
    }
    
    int get(int index, int snap_id) {
        auto it = A[index].upper_bound(snap_id); //returns value (snap id) from MAP greater than snap_id
        return it==begin(A[index])?0:prev(it)->second; //If no value greater, i.e. iterator still pointing at start = return 0, else return the prev of upperbound-> that can equal or less than snap_id we want ->second (value)
    }
};
