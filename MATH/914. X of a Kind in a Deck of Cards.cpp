https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/


class Solution {
public:

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

bool hasGroupsSizeX(vector<int>& deck) {
    if(deck.size()<2){
        return false;
    }
    
    //frequency table
    unordered_map<int,int>mp;
    for(int i=0;i<deck.size();i++){
        mp[deck[i]]++;
    }
    
    //finding the gcd of frequency to forming group of equal number of eelemnt
    int res=0;
    for(auto x:mp){
        res=gcd(x.second,res);
    }
    
    //because it is given x>=2
     if(res>=2){
         return true;
     }
    return false;
}
};
