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
