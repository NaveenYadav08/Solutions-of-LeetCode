// link https://leetcode.com/problems/minimum-time-difference/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        sort(timePoints.begin(),timePoints.end());
        for( auto x:timePoints )
        {
           cout<<x<<endl;
        }
        
        int ans = INT_MAX;
        
        for(int i=0; i<timePoints.size()-1; i++)
        {
            string s1 = timePoints[i];
            string s2 = timePoints[i+1];
                
                int a1=0;
                int a2=0;
            
                a1+= stoi(s1.substr(0,2))*60;
                a2+= stoi(s2.substr(0,2))*60;
            
                a1+= stoi(s1.substr(3,2));
                a2+= stoi(s2.substr(3,2));
            
            int a = abs(a2-a1);
            ans= min(ans,min(a,1440-a));
            
                 
                
            
        }
        
            string s1 = timePoints[0];
            string s2 = timePoints[timePoints.size()-1];
                
                int a1=0;
                int a2=0;
            
                a1+= stoi(s1.substr(0,2))*60;
                a2+= stoi(s2.substr(0,2))*60;
            
                a1+= stoi(s1.substr(3,2));
                a2+= stoi(s2.substr(3,2));
            
            int a = abs(a2-a1);
            ans= min(ans,min(a,1440-a));
        
        
        
        
        
        return ans;
        
    }
};
