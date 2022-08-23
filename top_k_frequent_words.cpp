
class compare{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        unordered_map<string,int> map;
        for(auto it:words){
            map[it]++;
        }
        for(auto i:map){
            pq.push({i.second,i.first});
            
        }
        vector<string> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
























