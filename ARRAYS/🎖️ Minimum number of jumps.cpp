https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

https://leetcode.com/problems/jump-game-ii/

    int minJumps(int nums[], int n){
        int currReach = 0;
        // This variable keeps track of the maximum index (steps) that can be taken from the previous jump position..
        int currMax = 0; // MaxJump ( all pssble betwwen prv jump pst and currReach )
        int jumps = 0; // Final ANS
        
        for(int i=0;i<n-1; i++)
        {
            if(i+nums[i]>currMax)
            {
                currMax=i+nums[i]; 
                // it will see all the jump between till currReach  from previous jump to see the max possibilty 
            }
            
            if(i==currReach)
            {// when I reach at currReach i will have to  take the jump and update new reach as maxreach 
                jumps++;
                currReach = currMax;
            }

        }
        
        if(currReach<n-1)
        return -1;
        
        return jumps;
    }
