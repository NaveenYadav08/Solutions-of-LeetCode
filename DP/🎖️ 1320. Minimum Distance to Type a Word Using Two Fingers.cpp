// LINK https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/


// CODE 

// [Hint 2] dp[i][j][k]: smallest movements when you have one finger on i-th char and the other one on j-th char already having written k first characters from word.


// dist = \ x2 - x1 \ + \ y2 - y1 \
// iniital position of fingesrs are free to set 



class Solution {
    
unordered_map<char, pair<int,int>> keyboard;
    // char ko uske index se map krna 
    
unordered_map<string, int> memo;
    
string words; // to make it global //

int dist(char &c1, char &c2){
    if(c1=='s' or c2=='s') return 0;
    
    pair<int,int> p1 = keyboard[c1];
    pair<int,int> p2 = keyboard[c2];
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int helper(int i, char &f1, char &f2){
   
    if(i==words.size()) return 0;
    string key = to_string(i)+ f1+f2; // key in map
    
    if(memo.count(key)) { return memo[key];}
    
    // choice 1 =  move finger 1 to a new position and keep finger 2 same
    int choice1 = dist(f1,words[i]) + helper(i+1, words[i], f2);
    
        
    // choice 1 =  move finger 2 to a new position and keep finger 1 same
    int choice2 = dist(f2, words[i]) + helper(i+1, f1, words[i]);
    
    // cout<<"( "<<i<<" "<<f1<<" "<<f2<<" )"<<endl;
    // cout<<choice1<<" "<<"( "<<i+1<<" "<<words[i]<<" "<<f2<<" )"<<endl;
    // cout<<choice2<<" "<<"( "<<i+1<<" "<<f1<<" "<<words[i]<<" )"<<endl;
    // cout<<endl;
    
    return memo[key] = min(choice1, choice2);
}
    
public:
    
int minimumDistance(string word) {
    words = word;
    
    // i = A to Z
    for(int i=65; i<=90; i++)
    {keyboard[char(i)] = {(i-65)/6, (i-65)%6};} // set position of word on keyboard
    
    // char s = ? // any arbitary char not in keyboard for inital ones 
    char s= 's';
    keyboard['s']={0,0}; // for start elements 
    return helper(0,s,s);
}
    
    
};
