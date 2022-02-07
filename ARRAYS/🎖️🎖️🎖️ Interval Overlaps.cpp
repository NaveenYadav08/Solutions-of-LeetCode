https://binarysearch.com/problems/Interval-Overlaps

// Intuition

// Traverse through lists and add to answer if overlapp is found.
// Implementation

// If the ending of one is less than the start of other then move the lesser ending ahead.
// Else add the max of starts, the min of ends in the answer array.
// Now do the same type of check to see which list element was exhausted and increment accordingly.
// Time Complexity

// O(n+m)\mathcal{O}(n + m)O(n+m) at each iteration at least one index will move.
// Space Complexity

// O(n)\mathcal{O}(n)O(n) for saving the answers, depends on how many overlaps were found.

vector<vector<int>> solve(vector<vector<int>>& l0, vector<vector<int>>& l1) {
    int i=0;
    int j=0;
    int n1=l0.size();
    int n2=l1.size();
    vector<vector<int>> ans;

    while(i<n1 and j<n2)
    {
        if(l0[i][1]<l1[j][0])
        i++;
        else if(l1[j][1]<l0[i][0])
        j++;

        else
        {
            vector<int> temp;
            temp.push_back(max(l0[i][0],l1[j][0]));
            temp.push_back(min(l0[i][1],l1[j][1]));
            ans.push_back(temp);

            if(l0[i][1]<l1[j][1])
            i++;
            else
            j++;
        }
    }

    return ans;
}
