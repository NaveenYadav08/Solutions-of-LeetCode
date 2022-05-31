// Leetcode -  https://leetcode.com/problems/my-calendar-i/


// i learned that if in set only 1 element prev will give that same ele itselg
// CODE 
class MyCalendar {
public:
    
    // track <start,end> tuple in sorted order of start
    map<int,int>startTrack;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        // insert start end if Map is empty
        if(startTrack.empty())
        {
           startTrack[start]=end;
           return true;
        }
  
        // get start > current and check if start < current end then its a overlap
        auto st  = startTrack.upper_bound(start);
        if(st!=startTrack.end() && st->first > start && st->first< end)return false;

        // get start <= current and check if end > current start then its a overlap
        st = prev(st);
        if(st->first <= start && st->second>start)return false;
        
        // if no overlap then add the <start,end> tuple in the Map
        startTrack[start]=end;
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
