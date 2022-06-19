https://leetcode.com/problems/design-twitter/

class Twitter {
private :  
    unordered_map<int, set<int>> follows;
    int time = 0;
    priority_queue<vector<int>> pq;
public:
    Twitter() {
        time = 0;
        follows.clear();
    
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({time++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int i=0;
        priority_queue<vector<int>> duplicate = pq;
        while(!duplicate.empty() and i<10){
            auto val = duplicate.top();
            duplicate.pop();
            if(val[1]==userId || follows[userId].count(val[1])){
                feed.push_back(val[2]);
                i++;
            }
              
        }
               return feed;
    }
               
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
