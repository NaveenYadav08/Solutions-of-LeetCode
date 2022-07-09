https://leetcode.com/problems/reaching-points/



/////////////////////////////////////////////////////////////

THEORY 
Method:

now let's say at some point we have coordinates as (a,b)
if(a>b) then at the previous step coordinate must be (a-b,b)
      as it can't be (a,b-a) because all the coordinates are positive and for a>b... b-a<0
this continues till the point when a becomes <=b
we can run a loop till there but its time taking
we can observe that the above phenomeon occurs till it becomes (a%b,b)
example :

for (50,7) it would have been like this:
(50,7)...(43,7)...(36,7)...........(8,7)..(1,7)
1 = 50%7  
    
By repeating this procedure, after the loop, we have to test if sx == tx or sy == ty. There is still a condition to test.
Let see we got sy = ty = 5 and have the following result
sx,sy = (16,5)
tx,ty = (21,5)
now if we run our program then it will stop at (1,5) which is not equal to sx,sy and will return false
however during our iteration we will encounter (16,5) infact after the first iteration only but according to our current code it won't detect it
so at the end we apply another condition:
check if (tx - sx) % ty == 0. In our case, (21 - 16) mod 5 = 0 so we can return true.



/////////////////////////////////////////////////////////////


class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        if (tx < sx || ty < sy)
        {
            return false;
        }
        if (tx == sx && (ty - sy) % sx == 0)
        {
            return true;
        }
        if (ty == sy && (tx - sx) % sy == 0)
        {
            return true;
        }
        while (tx > sx && ty > sy)
        {
            if (tx > ty)
            {
                tx = tx % ty;
            }
            else
            {
                ty = ty % tx;
            }
        }
        if (tx == sx && (ty - sy) % sx == 0)
        {
            return true;
        }
        if (ty == sy && (tx - sx) % sy == 0)
        {
            return true;
        }
        return false;
    }
};
