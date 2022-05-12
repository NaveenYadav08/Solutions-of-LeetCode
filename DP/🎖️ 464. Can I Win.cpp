

// link - https://leetcode.com/problems/can-i-win/


// code

class Solution {
public:
    unordered_map<int,int> mp;
    
    int rec(int state,int mx,int dt){
        
        if(mp.find(state)!=mp.end()) return mp[state];
        //memoize 
        
        
        int prev;
        for(int i=1;i<=mx;i++){
            if(state&(1<<i)) continue;
            prev=state;
            
            state|=(1<<i);
            
            // if A win ya B fail
            if(dt-i<=0 || !rec(state,mx,dt-i)){     
                state=prev;
                return mp[state]=1;
            }
            
            // backtrack
            state=prev;
        }
        
        return mp[state]=0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int mx=maxChoosableInteger, dt = desiredTotal;
        if((mx*(mx+1))/2 <dt) return false; //if sum of all 1 to mx is less than target , false
        
        return rec(0,mx,dt); // state, max, desiretarget
    }
};
