// Last updated: 5/17/2026, 12:00:22 AM
// gotta get back to it soon nga
1class Twitter {
2private:
3    int time;
4    unordered_map<int, unordered_set<int>> mp; // Stores followers
5    unordered_map<int, vector<pair<int, int>>>
6        mp2; // Stores tweets (time, tweetId)
7public:
8    Twitter() { time = 0; }
9
10    void postTweet(int userId, int tweetId) {
11        mp2[userId].emplace_back(time, tweetId);
12        time++;
13    }
14
15    vector<int> getNewsFeed(int userId) {
16        priority_queue<pair<int, int>> pq;
17        for (auto i : mp2[userId])
18            pq.push(i);
19        for (auto i : mp[userId]) {
20            for (auto j : mp2[i])
21                pq.push(j);
22        }
23        vector<int> feed;
24        int count = 10;
25        while (!pq.empty() && count) {
26            feed.push_back(pq.top().second);
27            pq.pop();
28            count--;
29        }
30        return feed;
31    }
32
33    void follow(int followerId, int followeeId) {
34        mp[followerId].insert(followeeId);
35    }
36
37    void unfollow(int followerId, int followeeId) {
38        mp[followerId].erase(followeeId);
39    }
40};
41
42/**
43 * Your Twitter object will be instantiated and called as such:
44 * Twitter* obj = new Twitter();
45 * obj->postTweet(userId,tweetId);
46 * vector<int> param_2 = obj->getNewsFeed(userId);
47 * obj->follow(followerId,followeeId);
48 * obj->unfollow(followerId,followeeId);
49 */