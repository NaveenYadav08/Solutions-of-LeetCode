https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/


APPROACH 1 = TRYING ALL THE BITMASK COMBINATIONS 

class Solution {
public:
  int calcScore(string &word, vector<int>&mp, vector<int>&score){
        int scre = 0;
        for(char c: word){
            if(mp[c-'a']==0) return INT_MIN;
            mp[c-'a']--;
            scre+=score[c-'a'];
        }
        return scre;
    }

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0, temp, n = words.size();
        vector<int>mp(26); // original map for freq in letters
    
        for(char c: letters) mp[c-'a']++; // stroing freq from letters
    
    
        for(int mask = 0; mask<(1<<n); mask++){//generating all combinations all POWER SET 
            
            temp = 0;
            vector<int>tmp = mp;//O(26)
            
            for(int i=0; i<n; i++){
                if(mask & 1<<i){//ith word is chosen
                    temp+=calcScore(words[i], tmp, score);
                    if(temp<0) break;
                }
            }
            res = max(res, temp);
        }
        return res;
    }
};



APPROACH 2 = TRYING DP 

class Solution {
public:
    void solve(vector<string> &words,vector<int> &scr,vector<int> &cnt,int curr_idx,int &n, int &ans,int temp_ans){
        if(curr_idx==n){
            ans = max(ans,temp_ans);
            return;
        }
        vector<int> tmp = cnt;
        solve(words,scr,cnt,curr_idx+1,n,ans,temp_ans);
        bool a = true;
        int scor = 0;
        for(auto &i: words[curr_idx]){
            tmp[i-'a']--;
            scor += scr[i-'a'];
            if(tmp[i-'a']<0){a = false;break;}
        }
        if(a) solve(words,scr,tmp,curr_idx+1,n,ans,temp_ans+scor);
    }


    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26,0);
        for(auto &i: letters){
            cnt[i-'a']++;
        }
        int ans = 0;
        int n = words.size();
        solve(words,score,cnt,0,n,ans,0);
        return ans;
        // temp_ans tmpans
        // s curridx
    }
};
