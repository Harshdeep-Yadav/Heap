class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<trips.size();i++){
            pq.push({trips[i][1],trips[i][0]});
            pq.push({trips[i][2],-trips[i][0]});
        }
        int onboard=0;
        while(!pq.empty()){
            onboard=onboard+pq.top().second;
            pq.pop();
            if(onboard>capacity)
                return false;
        }
        return true;
    }
};