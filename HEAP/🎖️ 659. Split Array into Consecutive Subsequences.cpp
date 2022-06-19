// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

// 659. Split Array into Consecutive Subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int lenLessThan3Count = 0;
        
        unordered_map< int, priority_queue<int, vector<int>, greater<int>>> record;
        
        for (auto num : nums) {
            
            if (record[num-1].empty()) {
                //cout<<num<<endl;
                //if(record[num-1].size()>1) cout<<"PAKODAA"<<endl;
                  record[num].push(1);
                
                lenLessThan3Count++;
                
            }
            else{
                
              
                
                int minCount = record[num-1].top();
                record[num-1].pop();
                record[num].push(++minCount);
                
                if (minCount == 3)
                    lenLessThan3Count--;
            }
        }
        
        return lenLessThan3Count == 0;
    }
};
