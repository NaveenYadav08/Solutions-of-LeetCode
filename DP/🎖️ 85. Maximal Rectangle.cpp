https://leetcode.com/problems/maximal-rectangle/

85. Maximal Rectangle

class Solution {
public:
int MAH(vector<int> &A,int n){
        vector<int> left(n,-1),right(n,n),st;
        for(int i=0;i<n;i++){
            while(st.size() and A[st.back()]>A[i]) st.pop_back();
            if(st.size()) left[i]=st.back();
            st.push_back(i);
        }
        st.clear();
        for(int i=0;i<n;i++){
            while(st.size() and A[st.back()]>A[i]){
                right[st.back()]=i;
                st.pop_back();
            }
            st.push_back(i);
        }
        int ans=0;
        for(int i=0;i<n;i++) ans=max(ans,(right[i]-left[i]-1)*A[i]);
        return ans;
    }
    
    // mae traverse krunga matrix ko or har ek col ka row wise sum krta rhunga 
    // after summing at each row I will use Laregst reactangle in histogram 
    
    // 1 1 0 1 0
    // 1 0 1 1 1
        
        // so iska jo seen hae sum at row 0 = 1 1 0 1 0
        // sum at row 1 give                  2 0 1 2 1
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=size(matrix),n=size(matrix[0]),res=0;
        vector<int> A(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') A[j]=0;
                else A[j]+=1;
            }
            res=max(res,MAH(A,n));
        }
        return res;
    }
};

