


https://leetcode.com/problems/asteroid-collision/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int curr=arr[i];
			//Only handle when new element is negative, else if positive , simply push to stack
            if(curr<0){
                while(!s.empty() && s.top()>0 && s.top()<abs(curr)){
                    s.pop();
                }
                if(s.empty() || s.top()<0)
                    s.push(curr);
                else if(s.top()==abs(curr)){
                    s.pop();
                }
            }
            else
                s.push(curr);
        }
        
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
