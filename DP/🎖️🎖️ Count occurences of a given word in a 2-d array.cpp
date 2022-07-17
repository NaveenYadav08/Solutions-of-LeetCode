https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1

class Solution{
    public:
    int findOccurrence(vector<vector<char> > &mat, string target){
        int count = 0;
        for(int i = 0; i < mat.size() ; i++){
            for(int j = 0; j < mat[i].size(); j++){
                count += findPath(mat, target, i, j, 0);
            }
        }
        return count;
    }
    
    int findPath(vector<vector<char> > mat, string target, int startX, int startY, int targetIndex){
        
        if(startX < 0 || startY < 0 || startX >= mat.size() || startY >= mat[startX].size()){
            return 0;
        }
        
        char original = mat[startX][startY];
        
        if(original != target[targetIndex])
            return 0;
        
        if(targetIndex == target.size() - 1)
            return 1;

        int count = 0;
        mat[startX][startY] = '\0';         // avoid return back to visited node

        count += findPath(mat, target, startX+1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY+1, targetIndex+1);
        count += findPath(mat, target, startX-1, startY, targetIndex+1);
        count += findPath(mat, target, startX, startY-1, targetIndex+1);
        
        mat[startX][startY] = original;
        return count;
    }
};
