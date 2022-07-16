https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/


Time Complexity will be O(n1 + n2) , where n is the length of the strings.
Auxiliary Space: O(n)
  
  
  CODE"''
  
  
  
bool check_rotation(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    queue<char> q1;
    for (int i = 0; i < s.size(); i++) {
        q1.push(s[i]);
    }
    queue<char> q2;
    for (int i = 0; i < goal.size(); i++) {
        q2.push(goal[i]);
    }
    int k = goal.size();
    while (k--) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q2 == q1)
            return true;
    }
    return false;
}
