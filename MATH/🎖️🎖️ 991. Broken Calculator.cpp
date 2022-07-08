https://leetcode.com/problems/broken-calculator/



////////////////////////////////////////////////////////
GREEDY
class Solution {
public:
    int brokenCalc(int num, int t){
        int oper = 0;
        while(t > num){
            if(t % 2) t++;
            else t /= 2;
            oper++;
        }
        return oper + (num - t);
    }
};


//////////////////////////////////////////////////////////////////////
RECURSION
class Solution {
public:
    int brokenCalc(int start, int target) {
        
        
        if(start >= target)
            return start-target;
		
        return 1 + (target%2 == 0 ? brokenCalc(start, target/2) : brokenCalc(start, target+1));
    
        
    }
};
