// LINK  https://leetcode.com/problems/make-array-strictly-increasing/

?? CODE 


// Current state can be found by looking at the previously picked element.


// 1- if prev element is smaller than the current element then we have the current element as a candidate to the final sequence hece we take it and move to next position.

// 2- if there exists an element in arr2 which is greater than the prev element we can pick it up and try to go further with it.


// NOTE :- we try to pick then minimum element at the current position which is greater than the prec element hence sort the arr2.



class Solution {
public:
    int help(map<pair<int,int>,int>&m,int prev,int i,vector<int>& arr1, vector<int>& arr2)
    {
        if(i==arr1.size()) return 0;
       //cout<<i<<" "<<prev<<endl;
        if(m.find({i,prev})!=m.end()) return m[{i,prev}];
        int ans=INT_MAX/2;
        int f=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(arr1[i]>prev)ans=min(ans,help(m,arr1[i],i+1,arr1,arr2));
        if(f<arr2.size())ans=min(ans,help(m,arr2[f],i+1,arr1,arr2)+1);
        //cout<<endl;
        return m[{i,prev}]=ans;
        
        // from index i till end and considering my prev index as prev  = min ans kya hoga 
        
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) 
    {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> m;
        int ans= help(m,INT_MIN,0,arr1,arr2); // map, prev, i, arr1,arr2
        return ans==INT_MAX/2?-1:ans;
    }
};
