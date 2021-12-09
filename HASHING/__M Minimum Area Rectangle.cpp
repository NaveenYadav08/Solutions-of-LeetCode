// MUST KNOW THIS DIAGONAL METHOD IN THE QUESTIONS LIKE THIS 
// which is take two diagonal opp poitns to form a rectangle 

// LEETCODE - https://leetcode.com/problems/minimum-area-rectangle/


// CODE 

class Solution {
public:
    
    
    int minAreaRect(vector<vector<int>>& points) {
        int ans=INT_MAX;
        
        int area=INT_MAX;
        set<pair<int,int>> st;
        
        for(auto x: points){
            st.insert({x[0],x[1]});
        }
        
        sort(points.begin(),points.end());
        for(int i=0;i<points.size();i++){
              int x1=points[i][0];
              int y1=points[i][1];
            for(int j=i+1;j<points.size();j++){
                
                int x2=points[j][0];
                int y2=points[j][1];
                
                if(st.find({x1,y2})!=st.end() and st.find({x2,y1})!=st.end()){
                    
                     int width = abs(x1 - x2);
                     int height= abs(y1 - y2);
                    
                    if(width*height>0){
                         area=min(area,width*height);
                    }
                   
                }
               
            }
           
        }
        
        return area==INT_MAX ? 0 : area;
    }
};
