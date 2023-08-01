#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    // a hashmap to store the followers
    map<int, set<int>> friends;
    // hashmap to store the posts
    map<int, vector<pair<int, int>>> posts;
    // count to store the number of tweets
    int cnt = 0;

public:
    // Initialize your data structure here
    Twitter() {}

    // Compose a new tweet
    void postTweet(int userId, int tweetId)
    {
        posts[userId].push_back({cnt, tweetId});
        cnt++;
    }

    // Retrieve the 10 most recent tweet ids as mentioned in question
    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        // tweets by the user
        for (auto i : posts[userId])
            pq.push(i);

        for (auto i : friends[userId])
        {
            for (auto j : posts[i])
            {
                pq.push(j);
            }
        }

        while (ans.size() < 10 && !pq.empty())
        {
            int tweet = pq.top().second;
            pq.pop();
            ans.push_back(tweet);
        }

        return ans;
    }

    // Follower follows a followee. If the operation is invalid, it should be a
    // no-op.
    void follow(int followerId, int followeeId)
    {
        friends[followerId].insert(followeeId);
    }

    // Follower unfollows a followee. If the operation is invalid, it should be
    // a no-op.
    void unfollow(int followerId, int followeeId)
    {
        if (friends[followerId].count(followeeId))
            friends[followerId].erase(followeeId);
    }
};

//{ Driver Code Starts.

int main()
{
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--)
    {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1)
        {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        }
        else if (query == 2)
        {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec)
                cout << a << " ";
            cout << endl;
        }
        else if (query == 3)
        {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        }
        else
        {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}