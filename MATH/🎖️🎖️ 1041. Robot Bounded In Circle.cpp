https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string ins) {
        
        int i=0; int y=0; // going to uppdate 
        int j=0;
        
        int ii=0; int yi=0;  // originals
        int ji=0;
        
        for(int I=0; I<ins.size(); I++)
        {   
            if(ins[I]=='G' and (j==0)) // j==0 north
            y++;
            
            else if(ins[I]=='G' and (j==1))  // j==1  east
            i++;
            
            else if(ins[I]=='G' and (j==2))  // j==2 south
            y--;
             
            else if(ins[I]=='G' and (j==3))  // j==3 west
            i--;
            
            else if(ins[I]=='L')
                j--;
            else if (ins[I]=='R')
                j++;
               
            j=(j+4)%4;
        }
        
        if( (j==ji) and ((i!=ii) or yi!=y)) // if it is ointing to north and not at 0 ,0 
            // then will expand infintely 
               return false;
               
               return true;
               
        
    }
};
