class Twitter {
public:
    map<int,set<int>> map;
    int currtime=0;
    priority_queue<vector<int>> pq;
    Twitter() {
        map.clear();
        currtime=0;
        pq=priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({currtime++,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> usertimeline=pq;
        int n=0;
        while(!usertimeline.empty()&&n<10){
            auto topTweet= usertimeline.top();
            usertimeline.pop();
            if(topTweet[2]==userId||  map[userId].count(topTweet[2])  ){
                ans.push_back(  topTweet[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         map[followerId].erase(followeeId);
    }
};
