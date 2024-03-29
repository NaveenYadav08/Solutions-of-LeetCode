https://leetcode.com/problems/text-justification/

https://www.youtube.com/watch?v=GqXlEbFVTXY

https://www.youtube.com/watch?v=GqXlEbFVTXY
https://leetcode.com/problems/text-justification/

TC = lines X maxWidth



class Solution {
public:
    
string middleJustify(vector<string>& words,int diff, int i, int j)
{
    
    int spacesNeeded = j-i-1; // kitne words ke beech me spread krna hae
    int spaces = diff/spacesNeeded;
    int extraSpaces = diff%spacesNeeded;
    
    string result=words[i];
    for(int k=i+1;k<j;k++)
    {   int spacesToApply = spaces +(extraSpaces-- > 0 ? 1:0);
         
     for(int I=0;I<spacesToApply;I++)
        result+=" ";
        
        result+=words[k];
        
    }

    
    return result;
}
    
    
string leftJustify(vector<string>& words,int diff, int i, int j)
{
    
    int spacesOnRight = diff- (j-i-1);
    string result=words[i];
    for(int k=i+1;k<j;k++)
    {
        result+=(" "+words[k]);
        
    }
    for(int I=0;I<spacesOnRight;I++)
        result+=" ";
    
    return result;
}
    
    
    
    
    
    
    
    
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i=0, n=words.size();
        while(i<n)
        {
          int j=i+1;
            int lineLength = words[i].size();  // has sum of all words added omly words 
            while(j<n && (lineLength + words[j].size() +(j-i))<=maxWidth )
            {
                lineLength+= words[j].size();
                ++j;
            }
            
            int diff=maxWidth-lineLength; /// spaces to spread
            int numberOfWords = j-i;
            if(numberOfWords == 1 || j >= n)
                result.push_back(leftJustify(words,diff,i,j));
            else
                result.push_back(middleJustify(words,diff,i,j));
            
            i=j;
                
        }
        
        return result;
    }
};
