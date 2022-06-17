https://leetcode.com/problems/gas-station/


class Solution {
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int position =0 , sum =0 , total =0;
        
        for(int index=0;index<gas.size();index++){
            sum += gas[index] - cost[index];
            
            if(sum<0){
                total+=sum;
                sum=0;
                position = index+1;
            }
        }
        
        total += sum;
        
        return total>=0?position:-1;
    }
};
